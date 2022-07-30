#ifndef CLL_H
#define CLL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct circular_linked_list
{
    int data;
    struct circular_linked_list *next;
} cll;

void menu();
void add_at_beg(cll **);
void print(cll *);
void search(cll *);
void delete (cll **);
void append(cll **);
void add_in_bet(cll **);
int count(cll *);

#endif