#ifndef TBT_H
#define TBT_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node {
    struct node *left, *right;
    int data;

    // if left pointer points to predecessor
    // in inorder traversal then false
    bool lthread;

    // if right pointer points to predecessor
    // in inorder traversal then false
    bool rthread;
} Node;

Node* insert(Node*, int);
Node* delete(Node*, int);
void inorder(Node*);

#endif
