#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *left;
    struct node *right;
    int data;
} node;

node* new_node(int data);
node* insert(node *root, int data);
node* get_max(node *root);
node* delete (node *root, int data);
int find(node *root, int data);

#endif