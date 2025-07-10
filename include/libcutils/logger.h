#ifndef LOGGER_H
#define LOGGER_H

/* *****************************************************************************
 * API
 ******************************************************************************/
#define LOG_LEVEL_TRACE   1
#define LOG_LEVEL_DEBUG   2
#define LOG_LEVEL_INFO    3
#define LOG_LEVEL_WARNING 4
#define LOG_LEVEL_ERROR   5
#define LOG_LEVEL_NONE    6

#define LOG_LEVEL_TRACE_TXT   "Trace  "
#define LOG_LEVEL_DEBUG_TXT   "Debug  "
#define LOG_LEVEL_INFO_TXT    "Info   "
#define LOG_LEVEL_WARNING_TXT "Warning"
#define LOG_LEVEL_ERROR_TXT   "Error  "

#ifndef LOG_LEVEL
  #define LOG_LEVEL LOG_LEVEL_TRACE
#endif

#ifndef ENABLE_LOG_COLORS
  #define ENABLE_LOG_COLORS 1
#endif

#define MAX_LOG_MSG_LENGTH 255

// ---------------------------------------------------------------------------------------------------------------------

#include <stdarg.h>
#include <stddef.h>
#include <string.h>


#if LOG_LEVEL == LOG_LEVEL_NONE
	#define simple_logger( ... )
#else
	void simple_logger( const char* level, const char* location, int line, const char* fmt, ... );
#endif

/*
 * not very secure solution, but __FUNCTION__ is no ISO-C Precompiler definition and therefore not compilable with
 * -Wpedantic flag. __FILE__ itself contains the whole filepath, which could be pretty long, so this macro just returns
 * the filename and nothing else.
 */
#define LOG_LOCATION ( strrchr( __FILE__, '/' ) + 1 )

#if LOG_LEVEL > LOG_LEVEL_TRACE
	#define log_trace( ... )
#else
	#define log_trace( fmt, ... ) simple_logger( LOG_LEVEL_TRACE_TXT, LOG_LOCATION, __LINE__, fmt, ##__VA_ARGS__ )
#endif

#if LOG_LEVEL > LOG_LEVEL_DEBUG
	#define log_debug( ... )
#else
	#define log_debug( fmt, ... ) simple_logger( LOG_LEVEL_DEBUG_TXT, LOG_LOCATION, __LINE__, fmt, ##__VA_ARGS__ )
#endif

#if LOG_LEVEL > LOG_LEVEL_INFO
	#define log_info( ... )
#else
	#define log_info( fmt, ... ) simple_logger( LOG_LEVEL_INFO_TXT, LOG_LOCATION, __LINE__, fmt, ##__VA_ARGS__ )
#endif

#if LOG_LEVEL > LOG_LEVEL_WARNING
	#define log_warning( ... )
#else
	#define log_warning( fmt, ... ) simple_logger( LOG_LEVEL_WARNING_TXT, LOG_LOCATION, __LINE__, fmt, ##__VA_ARGS__ )
#endif

#if LOG_LEVEL > LOG_LEVEL_ERROR
	#define log_error( ... )
#else
	#define log_error( fmt, ... ) simple_logger( LOG_LEVEL_ERROR_TXT, LOG_LOCATION, __LINE__, fmt, ##__VA_ARGS__ )
#endif

/* *****************************************************************************
 * Implementation
 ******************************************************************************/
#ifdef RESULT_IMPLEMENTATION

/*
 * only implement logging functions and file content if logging is enabled,
 * otherwise let this file be empty
 */
#if LOG_LEVEL != LOG_LEVEL_NONE

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

#define LOG_COLOR_ERROR   "\x1b[31m"
#define LOG_COLOR_WARNING "\x1b[33m"
#define LOG_COLOR_END     "\x1b[0m"

void simple_logger(const char *level, const char *location, int line,
                   const char *fmt, ...)
{
#if ENABLE_LOG_COLORS
	if (strncmp(level, LOG_LEVEL_WARNING_TXT, strlen(LOG_LEVEL_WARNING_TXT)) == 0) {
		printf(LOG_COLOR_WARNING);
	}
	else if (strncmp(level, LOG_LEVEL_ERROR_TXT, strlen(LOG_LEVEL_ERROR_TXT)) == 0) {
		printf(LOG_COLOR_ERROR);
	}
#endif

	printf("[%s] %s:%d  ", level, location, line);

	va_list arg_list;
	va_start(arg_list, fmt);
	vprintf(fmt, arg_list);

#if ENABLE_LOG_COLORS
	printf(LOG_COLOR_END);
#endif

	va_end(arg_list);
}

#endif // #if LOG_LEVEL != LOG_LEVEL_NONE%
#endif // RESULT_IMPLEMENTATION
#endif
