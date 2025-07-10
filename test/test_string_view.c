#include "testutils.h"

#define STRING_VIEW_IMPLEMENTATION
#include "libcutils/string_view.h"

#include <string.h>

static void test_string_view__from_parts(void)
{
	const char *s = "hello world!";

	String_View sv = sv_from_parts(s, strlen(s));

	TEST_ASSERT_EQ_INT(strlen(s), sv.length);
	TEST_ASSERT_EQ_STRN(s, sv.data, strlen(s));
}

static void test_string_view__from_cstr(void)
{
	const char *s = "hello world!";

	String_View sv = sv_from_cstr(s);

	TEST_ASSERT_EQ_INT(strlen(s), sv.length);
	TEST_ASSERT_EQ_STRN(s, sv.data, strlen(s));
}

static void test_string_view__eq_cstr(void)
{
	const char *s = "hello world!";

	String_View sv = sv_from_cstr(s);

	TEST_ASSERT_EQ_BOOL(true, sv_eq_cstr(&sv, s));
	TEST_ASSERT_EQ_BOOL(true, sv_eq_cstr(&sv, "hello world!"));
	TEST_ASSERT_EQ_BOOL(false, sv_eq_cstr(&sv, "hello world"));
	TEST_ASSERT_EQ_BOOL(false, sv_eq_cstr(&sv, "hello world!!"));
}

static void test_string_view__ltrim(void)
{
	const char *s = "    hello world!   ";

	String_View sv         = sv_from_cstr(s);
	String_View sv_trimmed = sv_ltrim(&sv);

	TEST_ASSERT_EQ_BOOL(true, sv_eq_cstr(&sv, s));
	TEST_ASSERT_EQ_BOOL(true, sv_eq_cstr(&sv_trimmed, "hello world!   "));
}

static void test_string_view__rtrim(void)
{
	const char *s = "hello world!";

	String_View sv         = sv_from_cstr(s);
	String_View sv_trimmed = sv_rtrim(&sv);

	TEST_ASSERT_EQ_INT(strlen(s), sv_trimmed.length);
	TEST_ASSERT_EQ_BOOL(true, sv_eq_cstr(&sv, s));
	TEST_ASSERT_EQ_BOOL(true, sv_eq_cstr(&sv_trimmed, "hello world!"));
}

static void test_string_view__copy(void)
{
	const char *s = "    hello world!   ";

	String_View sv     = sv_from_cstr(s);
	String_View sv_cpy = sv_copy(&sv);
	
	TEST_ASSERT_EQ_INT(sv.length, sv_cpy.length);
	TEST_ASSERT_EQ_STRN(sv.data, sv_cpy.data, sv.length);

	sv.length = 1;
	TEST_ASSERT_NEQ_INT(sv.length, sv_cpy.length);
}

void main_test_string_view(void)
{
	RUNTEST(test_string_view__from_parts);
	RUNTEST(test_string_view__from_cstr);
	RUNTEST(test_string_view__eq_cstr);
	RUNTEST(test_string_view__ltrim);
	RUNTEST(test_string_view__rtrim);
	RUNTEST(test_string_view__copy);
}
