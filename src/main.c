// dssh - Drewslam's Shell
// Author: Andrew Souza
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/queue.h"
#include "../include/exec.h"

#define MAX_LINE_LEN 1024

int main(void) {
  char input[MAX_LINE_LEN];
  while (1) {
    printf("dssh> ");
    if (!fgets(input, MAX_LINE_LEN, stdin))
      break;

    input[strcspn(input, "\n")] = '\0'; // remove newline
    if (input[0] == '\0')
      continue;
    if (strcmp(input, "exit") == 0)
      break;

    WordQueue queue;
    initWordQueue(&queue);

    char *token = strtok(input, " ");
    while (token != NULL) {
      Word *queuedWord = malloc(sizeof(Word));
      if (!queuedWord) {
        fprintf(stderr, "Memory allocation failed");
        exit(EXIT_FAILURE);
      }
      initWord(queuedWord, token);
      enqueue(&queue, queuedWord);
      token = strtok(NULL, " ");
    }

    handle_exec(&queue);

    freeWordQueue(&queue);
  }

  return 0;
}
