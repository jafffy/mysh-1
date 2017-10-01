#include "utils.h"

#include <stdlib.h>
#include <string.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
  const int kMaxArgc = 512;
  *argv = (char**)malloc(kMaxArgc);

  char buf[4096];
  strcpy(buf, command);

  char *tok = strtok(buf, " \n\t");

  int ti = 0;

  while (tok != NULL) {
    (*argv)[ti] = (char*)malloc(strlen(tok));
    strcpy((*argv)[ti], tok);

    ++ti;

    tok = strtok(NULL, " \n\t");
  }

  *argc = ti;

  if (*argc == 0) {
    *argc = 1;
    (*argv)[0] = (char*)malloc(1);
    (*argv)[0][0] = '\0';
  }
}
