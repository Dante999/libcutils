#ifndef STRING_VIEW_H
#define STRING_VIEW_H

/* *****************************************************************************
 * API
 ******************************************************************************/
#include <stddef.h>
#include <stdbool.h>

typedef struct {
    const char *data;
    size_t length;
} String_View;


String_View sv_from_parts(const char *s, size_t len);
String_View sv_from_cstr(const char *s);
bool sv_eq_cstr(const String_View *sv, const char *s);

String_View sv_copy(const String_View *sv);
String_View sv_ltrim(const String_View *sv);
String_View sv_rtrim(const String_View *sv);

/* *****************************************************************************
 * Implementation
 ******************************************************************************/
#ifdef STRING_VIEW_IMPLEMENTATION

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

String_View sv_ltrim(const String_View *sv)
{
	size_t i=0; 
	while (i < sv->length && is_whitespace(sv->data[i])) {
		++i;
	}

	return sv_from_parts(sv->data + i, sv->length -i);
}


String_View sv_rtrim(const String_View *sv)
{
	size_t i = sv->length;
	while (i > 0 && is_whitespace(sv->data[i-1])) {
		--i;
	}

	return sv_from_parts(sv->data, i);
}

String_View sv_copy(const String_View *sv)
{
	return sv_from_parts(sv->data, sv->length);
}

#endif

#endif // STRING_VIEW_H
