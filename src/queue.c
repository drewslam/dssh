// dssh - Drewslam's Shell
#include <stdio.h>
#include <stdlib.h>
#include "../include/queue.h"

void initWord(Word* word, char* in) {
  word->word = in;
  word->next = NULL;
  word->prev = NULL;
}

void initWordQueue(WordQueue *w) {
  w->head = NULL;
  w->tail = NULL;
  w->size = 0;
}

void enqueue(WordQueue *w, Word *word) {
  if (w->head == NULL) {
    w->head = w->tail = word;
    return;
  }

  w->tail->next = word;
  word->prev = w->tail;
  w->tail = word;
  w->size++;
}

bool dequeue(WordQueue *w, Word *word) {
  Word *curr = w->head;
  while (curr != NULL && curr != word) {
    curr = curr->next;
  }
  if (curr == NULL) {
    printf("failed to retrieve word (%s)", word->word);
    return false;
  }
  if (curr->prev != NULL) {
    curr->prev->next = curr->next;
  } else {
    w->head = curr->next; // Removing head
  }
  if (curr->next != NULL) {
    curr->next->prev = curr->prev;
  } else {
    w->tail = curr->prev; // Removing tail
  }
  free(curr);
  w->size--;
  return true;
}

Word* front(WordQueue *w) { return w->head; }

bool isEmpty(WordQueue *w) { return w->head == NULL; }

int size(WordQueue* w) { return w->size; }
