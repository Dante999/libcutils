#ifndef STRING_VIEW_H
#define STRING_VIEW_H

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

#endif // STRING_VIEW_H
