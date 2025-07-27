// dssh - Drewslam's Shell
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_INPUT 1024

int main(int argc, const char** argv) {
  char input[MAX_INPUT];
  while (strcmp(input, "exit") != 0) {
    char temp;
    size_t i = 0;
    printf("dssh> ");
    while (i < MAX_INPUT - 1 && scanf("%c", &temp) == 1 && temp != '\n') {
      input[i++] = temp;
    }
    input[i] = '\0';
  
    i = 0;
    while (input[i] != '\0') {
      printf("%c", input[i++]);
    }
    printf("\n");
  }

  return 0;
}
