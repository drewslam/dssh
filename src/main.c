// dssh - Drewslam's Shell
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "../include/queue.h"

#define MAX_INPUT 1024
#define MAX_WORD_LEN 50

int main(void) {
  char input[MAX_INPUT];
  while (1) {
    printf("dssh> ");
    if (!fgets(input, MAX_INPUT, stdin))
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
    char command[MAX_WORD_LEN];
    strcpy(command, queue.head->word);

    int rc = fork();

    if (rc == 0) {
      char *args[queue.size + 1];
      Word *tmp = queue.head->next;
      args[0] = command;
      for (int i = 0; i < queue.size; i++) {
        args[i + 1] = tmp->word;
        tmp = tmp->next;
      }
      args[queue.size] = NULL;
      execvp(command, args);
      perror("exec failure");
      exit(EXIT_FAILURE);
    } else {
      wait(NULL);
    }

    freeWordQueue(&queue);
  }

  return 0;
}
