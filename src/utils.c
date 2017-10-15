#include "utils.h"

#include <stdlib.h>
#include <string.h>

void mysh_parse_command(const char* command,
                        int* n_commands,
                        struct single_command** commands)
{
  const int kMaxPipes = 512;
  *commands = (struct single_command*)malloc(sizeof(struct single_command) * kMaxPipes);

  char buf[4096];
  strcpy(buf, command);

  char *saveptr = NULL;
  char *tok = strtok_r(buf, "|", &saveptr);

  int ti = 0;

  while (tok != NULL) {
  }

  *n_commands = ti;
}

void parse_single_command(const char* command,
                          int *argc, char*** argv)
{
  const int kMaxArgc = 512;
  *argv = (char**)malloc(kMaxArgc * sizeof(char*));

  char buf[4096];
  strcpy(buf, command);

  char *saveptr = NULL;
  char *tok = strtok_r(buf, " \n\t", &saveptr);

  int ti = 0;

  while (tok != NULL) {
    (*argv)[ti] = (char*)malloc(strlen(tok));
    strcpy((*argv)[ti], tok);

    ++ti;

    tok = strtok_r(NULL, " \n\t", &saveptr);
  }

  *argc = ti;

  if (*argc == 0) {
    *argc = 1;
    (*argv)[0] = (char*)malloc(1);
    (*argv)[0][0] = '\0';
  }
}
