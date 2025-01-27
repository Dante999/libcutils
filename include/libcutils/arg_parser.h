#ifndef ARG_PARSER_H
#define ARG_PARSER_H

#include <stdint.h>

#include "result.h"

void args_add_flag(const char *key);
void args_add_argument(const char *key);
void args_add_argument_with_default(const char *key, const char *default_value);

Result args_parse(int argc, char *argv[]);
Result args_verify();
void args_print();
void args_help(const char *program_name);

const char *args_gets(const char *key);
int         args_geti(const char *key);
bool        args_get_flag(const char *key);

#endif // ARG_PARSER_H
