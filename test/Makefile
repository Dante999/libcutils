
LIBCUTILS_SRC=../src/result.c \
	      ../src/arg_parser.c \
	      ../src/util_strings.c \

LIBCUTILS_INC=../include

LIBCUTILS_TESTBINARY=libcutils_test

all:
	${CC} -Wall -Wextra -Wpedantic -o ${LIBCUTILS_TESTBINARY} \
		-I ${LIBCUTILS_INC} \
		${LIBCUTILS_SRC} \
		main.c \
		test_util_makros.c

clean:
	rm ${LIBCUTILS_TESTBINARY}
