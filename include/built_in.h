#ifndef BUILT_IN_H_
#define BUILT_IN_H_

typedef int (*built_in_command_do)(int, char**);
typedef int (*built_in_command_validate)(int, char**);

struct built_in_command
{
  char command_name[512];
  built_in_command_do command_do;
  built_in_command_validate command_validate;
};

/**
  do_cd(argc, argv)

  params:
    argc: # of arguments. argc must be 2. just "cd" doesn't be approved.
    argv: a list of arguments.

  returns:
    If success, return 0.
    Else if arguments are not valid, return -1.
*/
int do_cd(int argc, char** argv);

/**
  do_pwd(argc, argv)

  params:
    argc: # of arguments. argc must be 1.
    argv: a list of arguments.

  returns:
    If success, return 0.
    Else if arguments are not valid, return -1.
*/
int do_pwd(int argc, char** argv);

int do_fg(int argc, char** argv);

/**
  validate_cd_argv(argc, argv)

  returns:
    If success, return 1. (true)
    Else return 0. (false)
*/
int validate_cd_argv(int argc, char** argv);
/**
  validate_pwd_argv(argc, argv)

  returns:
    If success, return 1. (true)
    Else return 0. (false)
*/
int validate_pwd_argv(int argc, char** argv);

int validate_fg_argv(int argc, char** argv);

#endif // BUILT_IN_H_
