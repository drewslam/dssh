// dssh - Drewslam's Shell
#include "../include/queue.h"
#include <fcntl.h>
#include <linux/limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include "../include/exec.h"
#include "../include/builtins.h"

void handle_fork(char* c[]) {
  int rc = fork();
  if (rc < 0) {
    perror("fork failure");
    return;
  }
  if (rc == 0) {
    execvp(c[0], c);
    perror("exec failure");
    exit(EXIT_FAILURE);
  } else {
    wait(NULL);
  }
}

void handle_exec(WordQueue *q) {
  if (q->size == 0 || q->head == NULL) {
    return;
  }

  char workingDir[PATH_MAX];
  char *args[q->size + 1];
  Word *tmp = q->head;
  for (int i = 0; i < q->size; i++) {
    args[i] = tmp->word;
    tmp = tmp->next;
  }
  args[q->size] = NULL;

  if (strcmp(args[0], "cd") == 0) {
    handleCD(args[1]);
  } else if (strcmp(args[0], "pwd") == 0) {
    handlePWD(workingDir);
  } else {
    handle_fork(args);
  }
}
