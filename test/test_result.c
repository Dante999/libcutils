#include "testutils.h"

#include "libcutils/result.h"

#include <errno.h>

static void test_result__success(void)
{
	Result res = make_result(true, "success!");

	TEST_ASSERT(true, res.success);
}

static void test_result__fail(void)
{
	Result res = make_result(false, "failed!");

	TEST_ASSERT(false, res.success);
}

static void test_result__from_errno(void)
{
	Result res = make_result_error(EEXIST);

	TEST_ASSERT(false, res.success);
}

static void test_result__fmt(void)
{
	Result res = make_result(true, "hello %s!", "world");

	TEST_ASSERT(true, res.success);
	TEST_ASSERT(0, strcmp("hello world!", res.msg));
}

void main_test_result(void)
{
	RUNTEST(test_result__success);
	RUNTEST(test_result__fail);
	RUNTEST(test_result__from_errno);
	RUNTEST(test_result__fmt);
}

