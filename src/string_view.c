#include "libcutils/string_view.h"

#include <string.h>
#include <stdbool.h>


static bool is_whitespace(char c)
{
	return (strchr(" \t\r\n", c) != NULL) ? true : false;
}



String_View sv_from_parts(const char *s, size_t len)
{
	String_View sv;
	sv.data   = s;
	sv.length = len;

	return sv;
}

String_View sv_from_cstr(const char *s)
{
	String_View sv;
	sv.data   = s;
	sv.length = strlen(s);

	return sv;
}

bool sv_eq_cstr(const String_View *sv, const char *s)
{
	if (strlen(s) != sv->length) return false;

	return (strncmp(sv->data, s, sv->length) == 0 ? true : false);
}

// TODO: Buggy function, returns garbage
String_View sv_ltrim(const String_View *sv)
{
	String_View sv_trimmed = {sv->data, sv->length};

	for( size_t i=0; i < sv->length; ++i) {

		if (!is_whitespace(sv->data[i])) {
			sv_trimmed.data   += i;
			sv_trimmed.length -= i;
		}
	}

	return sv_trimmed;
}
