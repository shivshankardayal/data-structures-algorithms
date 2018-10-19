#ifndef STACK_LL_H
#define STACK_LL_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Stack{
  int data;
  struct Stack *next;
}Stack;

void push(Stack**, int);
int pop(Stack**);
void menu();

#endif
