#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

const int MAX = 8;
int top = -1;

void push(int [], int);
int pop(int []);
bool IsEmpty();
void menu();

#endif
