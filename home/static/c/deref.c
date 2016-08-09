/*******************************************************************************
Linked list queue of ints
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int value;
  struct node *next;
} Node;

Node* new_queue(){
  Node* queue = (Node*)malloc(sizeof(Node));
  if (queue != 0){
    queue->next = 0;
  }
  return queue;
}

void delete_queue(Node *start){
  if (start){
    Node* prev;
    Node* current = start->next;
    while (current == 0){  //Should be (current != 0). Currently there is a potential 0 deref.
      prev = current;
      current = current->next; //@violation NULL_DEREF.MISSING_CHECK
      free(prev);
    }
    free(start);
  }
}

void push_back(Node *start, int val){
  if (start){
    Node* current = start;
    while (current->next != 0){
      current = current->next;
    }
    current->next = (Node*)malloc(sizeof(Node));
    current = current->next;
    if (current != 0){
      current->value = val;
      current->next = 0;
    }
  }
}

int pop_front(Node *start){
  int ret = 0;
  if (start){
    if (start->next != 0){
      Node* oldFirst = start->next;
      start->next = start->next->next;
      ret = oldFirst->value;
      free(oldFirst);
    }
  }
  return ret;
}
