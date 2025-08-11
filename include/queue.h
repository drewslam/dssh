// dssh - Drewslam's Shell
#ifndef DSSH_QUEUE
#define DSSH_QUEUE

#include <stdbool.h>

typedef struct Word {
  char* word;
  struct Word* next;
  struct Word* prev;
} Word;

typedef struct {
  Word* head;
  Word* tail;
  int size;
} WordQueue;


void initWord(Word* word, char* in);

void initWordQueue(WordQueue* w);

void freeWordQueue(WordQueue* w);

void enqueue(WordQueue* w, Word* word);

bool dequeue(WordQueue* w);

bool removeWord(WordQueue* w, Word* word);

Word* front(WordQueue* w);

bool isEmpty(WordQueue* w);

int getSize(WordQueue* w);

void printQueue(WordQueue* w);

#endif
