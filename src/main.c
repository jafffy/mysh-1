#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "commands.h"
#include "built_in.h"
#include "utils.h"

int main()
{
  char buf[8096];

  while (1) {
    fgets(buf, 8096, stdin);

    struct single_command commands[512];
    int n_commands = 0;
    mysh_parse_command(buf, &n_commands, &commands);

    for (int i = 0; i < n_commands; ++i) {
      struct single_command* com = commands + i;
      int argc = com->argc;
      char** argv = com->argv;
      for (int j = 0; j < argc; ++j) {
        printf("%s ", argv[j]);
      }
      printf("\n");
    }

    /*

    if (strcmp(argv[0], "") == 0) {
      goto release_and_continue;
    } else if (strcmp(argv[0], "cd") == 0) {
      if (do_cd(argc, argv)) {
        fprintf(stderr, "cd: Invalid arguments\n");
      }
    } else if (strcmp(argv[0], "pwd") == 0) {
      if (do_pwd(argc, argv)) {
        fprintf(stderr, "pwd: Invalid arguments\n");
      }
    } else if (strcmp(argv[0], "exit") == 0) {
      goto release_and_exit;
    } else {
      fprintf(stderr, "%s: command not found\n", argv[0]);
    }
release_and_continue:
    release_argv(argc, &argv);
    continue;
release_and_exit:
    release_argv(argc, &argv);
    break;
    */
  }

  return 0;
}
