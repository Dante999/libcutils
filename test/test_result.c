#include "testutils.h"

#define RESULT_IMPLEMENTATION
#include "libcutils/result.h"

#include <errno.h>

static void test_result__success(void)
{
	Result res = result_make(true, "success!");

	TEST_ASSERT_EQ_BOOL(true, res.success);
}

static void test_result__fail(void)
{
	Result res = result_make(false, "failed!");

	TEST_ASSERT_EQ_BOOL(false, res.success);
}

static void test_result__from_errno(void)
{
	Result res = result_make_error(EEXIST);

	TEST_ASSERT_EQ_BOOL(false, res.success);
}

static void test_result__fmt(void)
{
	Result res = result_make(true, "hello %s!", "world");

	TEST_ASSERT_EQ_BOOL(true, res.success);
	TEST_ASSERT_EQ_STR("hello world!", res.msg);
}

void main_test_result(void)
{
	RUNTEST(test_result__success);
	RUNTEST(test_result__fail);
	RUNTEST(test_result__from_errno);
	RUNTEST(test_result__fmt);
}

