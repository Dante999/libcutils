#include "testutils.h"

#include "libcutils/string_view.h"

#include <string.h>

static void test_string_view__from_parts(void)
{
	const char *s = "hello world!";

	String_View sv = sv_from_parts(s, strlen(s));

	TEST_ASSERT(0, strncmp(s, sv.data, strlen(s)));
	TEST_ASSERT(strlen(s), sv.length);
}

static void test_string_view__from_cstr(void)
{
	const char *s = "hello world!";

	String_View sv = sv_from_cstr(s);

	TEST_ASSERT(strlen(s), sv.length);
	TEST_ASSERT(0, strncmp(s, sv.data, strlen(s)));
}

static void test_string_view__eq_cstr(void)
{
	const char *s = "hello world!";

	String_View sv = sv_from_cstr(s);

	TEST_ASSERT(true, sv_eq_cstr(&sv, s));
	TEST_ASSERT(true, sv_eq_cstr(&sv, "hello world!"));
	TEST_ASSERT(false, sv_eq_cstr(&sv, "hello world"));
	TEST_ASSERT(false, sv_eq_cstr(&sv, "hello world!!"));
}

static void test_string_view__ltrim(void)
{
	const char *s = "    hello world!   ";

	String_View sv = sv_from_cstr(s);

	sv = sv_ltrim(&sv);

	TEST_ASSERT(true, sv_eq_cstr(&sv, "hello world!   "));
}

void main_test_string_view(void)
{
	RUNTEST(test_string_view__from_parts);
	RUNTEST(test_string_view__from_cstr);
	RUNTEST(test_string_view__eq_cstr);
	RUNTEST(test_string_view__ltrim);
}
