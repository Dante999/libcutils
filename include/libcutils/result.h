#ifndef RESULT_H
#define RESULT_H

/* *****************************************************************************
 * API
 ******************************************************************************/
#include <stdbool.h>
#include <stdarg.h>

typedef struct {
	bool success;
	char msg[255];
} Result;

void   result_set(Result *result, bool success, const char *fmt, ...);
void   result_vset(Result *result, bool success, const char *fmt, va_list args); 
Result result_make(bool success, const char *fmt, ...);
Result result_make_success(void);
Result result_make_error(int errno_val);

/* *****************************************************************************
 * Implementation
 ******************************************************************************/
#ifdef RESULT_IMPLEMENTATION

#include <errno.h>
#include <stdio.h>
#include <string.h>

void result_vset(Result *result, bool success, const char *fmt, va_list args)
{
	if (result == NULL) return;

	result->success = success;
	vsnprintf(result->msg, sizeof(result->msg), fmt, args);
}

void result_set(Result *result, bool success, const char *fmt, ...)
{
	if (result == NULL) return;

	va_list args;

	va_start(args, fmt);
	result_vset(result, success, fmt, args);
	va_end(args);
}


Result result_make(bool success, const char *fmt, ...)
{
	Result result;

	va_list args;

	va_start(args, fmt);
	result_vset(&result, success, fmt, args);
	va_end(args);

	return result;
}

Result result_make_error(int errno_val)
{
	Result result;
	result_set(&result, false, strerror(errno_val));
	return result;
}

Result result_make_success(void)
{
	Result result = {true, ""};
	return result;
}

#endif // RESULT_IMPLEMENTATION



#endif // RESULT_H
