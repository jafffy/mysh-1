#ifndef MYSH_UTILS_H_
#define MYSH_UTILS_H_

#include "commands.h"

void mysh_parse_command(const char* command,
                        int* n_commands,
                        struct single_command (*commands)[]);

void parse_single_command(const char* command,
                          int *argc, char*** argv);

#endif // MYSH_UTILS_H_
