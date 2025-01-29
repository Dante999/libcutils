#include "libcutils/result.h"

#include <errno.h>
#include <stdarg.h>
#include <stdio.h>

Result make_result_error(int errno_val)
{
	Result result;

	result.success = false;
	strncpy(result.msg, strerror(errno_val), sizeof(result.msg));

	return result;
}

Result make_result(bool success, const char *fmt, ...)
{
	Result result;
	result.success = success;

	va_list arg_list;

	va_start(arg_list, fmt);
	vsnprintf(result.msg, sizeof(result.msg), fmt, arg_list);
	va_end(arg_list);

	return result;
}

Result make_result_success(void)
{
	Result result = {true, ""};
	return result;
}

