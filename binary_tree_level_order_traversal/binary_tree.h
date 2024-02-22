#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *left;
    struct node *right;
    unsigned int height;
    int data;
} node;

node* insert(node* root, int data);
void levelOrder(node* root);
void levelOrderQueue(node* root);

#endif