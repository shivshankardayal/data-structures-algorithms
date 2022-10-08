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

node* newNode(int data, node* lt, node* rt);
node* insert(node* root, int data);
node* getMax(node *root);
node* delete (node **root, int data);
int find(node *root, int data);
void inorder(node* root);
void preorder(node* root);
void postorder(node* root);
unsigned int ht(node* root);
void rebalance(node** root);
void rotateRight(node **root);
void rotateLeft(node **root);
void doubleRotateRight(node **root);
void doubleRotateLeft(node **root);
void singleRotateRight(node **root);
void singleRotateLeft(node **root);

#endif