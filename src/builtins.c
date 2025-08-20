// dssh - Drewslam's Shell
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/limits.h>
#include "../include/builtins.h"

void handleCD(char *in) {
  if (in == NULL) {
    fprintf(stderr, "cd: missing target directory\n");
  } else if (chdir(in) != 0) {
    fprintf(stderr, "failed to cd: %s not found\n", in);
  }
}

void handlePWD() {
  char in[PATH_MAX];
  if (getcwd(in, PATH_MAX) != NULL) {
    printf("%s\n", in);
  } else {
    perror("pwd");
  }
}

bool isBuiltin(char *c[]) {
  if (c == NULL) {
    fprintf(stderr, "invalid command: cannot be NULL\n");
    return false;
  }
  if (strcmp(c[0], "cd") == 0) {
    handleCD(c[1]);
    return true;
  }
  if (strcmp(c[0], "pwd") == 0) {
    handlePWD();
    return true;
  }

  return false;
}
