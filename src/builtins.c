// dssh - Drewslam's Shell
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/limits.h>

void handleCD(const char *in) {
  if (in == NULL) {
    fprintf(stderr, "cd: missing target directory\n");
  } else if (chdir(in) != 0) {
    fprintf(stderr, "failed to cd: %s not found\n", in);
  }
}

void handlePWD(char *in) {
  if (getcwd(in, PATH_MAX) != NULL) {
    printf("%s\n", in);
  } else {
    perror("pwd");
  }
}
