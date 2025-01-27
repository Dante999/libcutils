
#include "testutils.h"

#include <stdio.h>
#include <stdint.h>

#include "libcutils/util_makros.h"

static void test_array_size__uint16()
{
	uint16_t myarray[8];
	TEST_ASSERT(8, ARRAY_SIZE(myarray));
}

static void test_array_size__char()
{
	char myarray[3];
	TEST_ASSERT(3, ARRAY_SIZE(myarray));
}

static void test_min()
{
	TEST_ASSERT(2,   MIN(2,10));
	TEST_ASSERT(3,   MIN(3,4));
	TEST_ASSERT(20,  MIN(20,20));
	TEST_ASSERT(100, MIN(101,100));
	TEST_ASSERT(0,   MIN(0,10));
	TEST_ASSERT(-10, MIN(-10,15));
}

static void test_max()
{
	TEST_ASSERT(10,  MAX(2,10));
	TEST_ASSERT(4,   MAX(3,4));
	TEST_ASSERT(20,  MAX(20,20));
	TEST_ASSERT(101, MAX(101,100));
	TEST_ASSERT(10,  MAX(0,10));
	TEST_ASSERT(15,  MAX(-10,15));
}

void main_test_util_makros()
{
	RUNTEST(test_array_size__uint16);
	RUNTEST(test_array_size__char);

	RUNTEST(test_min);
	RUNTEST(test_max);
}
