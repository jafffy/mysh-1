#ifndef MYSH_COMMANDS_H_
#define MYSH_COMMANDS_H_

struct single_command
{
  int argc;
  char** argv;
};

int evaluate_command(int n_commands, struct single_command (*commands)[]);

void free_commands(int n_commands, struct single_command (*commands)[]);

#endif // MYSH_COMMANDS_H_
