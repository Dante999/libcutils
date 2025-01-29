#ifndef RESULT_H
#define RESULT_H

#include <stdbool.h>
#include <string.h>

typedef struct {
	bool success;
	char msg[255];
} Result;

Result make_result_error(int errno_val);
Result make_result(bool success, const char *fmt, ...);
Result make_result_success(void);

#endif // RESULT_H
