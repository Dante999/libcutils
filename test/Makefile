CC_FLAGS = -Wall -Wextra -Werror -Wpedantic -I../include

all:
	${CC} ${CC_FLAGS} -o libcutils_test \
		main.c \
		test_arg_parser.c \
		test_logger.c \
		test_result.c \
		test_string_view.c \
		test_util_makros.c \
		test_util_strings.c

clean:
	rm libcutils_test
