#ifndef UTIL_STRINGS_H
#define UTIL_STRINGS_H

#include <stdbool.h>
#include <stddef.h>

bool  utils_strstartswith(const char *complete_str, const char *starter);
bool  utils_stranyof(const char *s, const char **probe_values, size_t probe_count);
char *utils_strltrim(char *s);
char *utils_strrtrim(char *s);
char *utils_strtrim(char *s);

#endif /* UTIL_STRINGS_H */
