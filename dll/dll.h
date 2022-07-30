#ifndef DLL_H
#define DLL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct d_linked_list
{
    int data;
    struct d_linked_list *next;
    struct d_linked_list *prev;
} dll;

void menu();
void add_at_beg(dll **);
void append(dll **);
void insert_after(dll **);
void insert_before(dll **);
void print(dll *);
void search(dll *);
int count(dll *);
void delete (dll **);

#endif