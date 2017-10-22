#ifdef __cplusplus
extern "C" {
#endif
#include "utils.h"
#include "commands.h"
#ifdef __cplusplus
}
#endif

#include "gtest/gtest.h"

#include <stdlib.h>

TEST(CommandParsingTest, BasicCommand) {
  struct single_command commands[512];
  int n_commands = 0;

  mysh_parse_command("cd test", &n_commands, &commands);

  ASSERT_EQ(n_commands, 1);
  ASSERT_EQ(commands[0].argc, 2);
  EXPECT_STREQ(commands[0].argv[0], "cd");
  EXPECT_STREQ(commands[0].argv[1], "test");

  free_commands(n_commands, &commands);
}

TEST(CommandParsingTest, SingleCommand) {
  struct single_command commands[512];
  int n_commands = 0;

  mysh_parse_command("pwd", &n_commands, &commands);

  ASSERT_EQ(n_commands, 1);
  ASSERT_EQ(commands[0].argc, 1);
  EXPECT_STREQ(commands[0].argv[0], "pwd");

  free_commands(n_commands, &commands);
}

TEST(CommandParsingTest, Redirection1) {
  struct single_command commands[512];
  int n_commands = 0;

  mysh_parse_command("pwd > curdir.txt", &n_commands, &commands);

  ASSERT_EQ(n_commands, 1);
  ASSERT_EQ(commands[0].argc, 3);
  EXPECT_STREQ(commands[0].argv[0], "pwd");
  EXPECT_STREQ(commands[0].argv[1], ">");
  EXPECT_STREQ(commands[0].argv[2], "curdir.txt");

  free_commands(n_commands, &commands);
}

TEST(CommandParsingTest, Redirection2) {
  struct single_command commands[512];
  int n_commands = 0;

  mysh_parse_command("pwd > curdir.txt | less", &n_commands, &commands);

  ASSERT_EQ(n_commands, 2);
  ASSERT_EQ(commands[0].argc, 3);
  EXPECT_STREQ(commands[0].argv[0], "pwd");
  EXPECT_STREQ(commands[0].argv[1], ">");
  EXPECT_STREQ(commands[0].argv[2], "curdir.txt");

  ASSERT_EQ(commands[1].argc, 1);
  EXPECT_STREQ(commands[1].argv[0], "less");

  free_commands(n_commands, &commands);
}

TEST(CommandParsingTest, SpaceBeforeString) {
  struct single_command commands[512];
  int n_commands = 0;

  mysh_parse_command("    \n  \t pwd > curdir.txt | less", &n_commands, &commands);

  ASSERT_EQ(n_commands, 2);
  ASSERT_EQ(commands[0].argc, 3);
  EXPECT_STREQ(commands[0].argv[0], "pwd");
  EXPECT_STREQ(commands[0].argv[1], ">");
  EXPECT_STREQ(commands[0].argv[2], "curdir.txt");

  ASSERT_EQ(commands[1].argc, 1);
  EXPECT_STREQ(commands[1].argv[0], "less");

  free_commands(n_commands, &commands);
}

TEST(CommandParsingTest, EmptyCommand) {
  struct single_command commands[512];
  int n_commands = 0;

  mysh_parse_command("   \n \t    ", &n_commands, &commands);

  ASSERT_EQ(commands[0].argc, 1);
  EXPECT_STREQ(commands[0].argv[0], "");

  free_commands(n_commands, &commands);
}
