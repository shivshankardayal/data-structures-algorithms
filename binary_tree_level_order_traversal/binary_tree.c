#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
#include "queue.h"

Queue *head = NULL;
Queue *tail = NULL;

node *newNode(int data)
{
    node *temp = (node *)malloc(sizeof(node));

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

node *insert(node *root, int data)
{
    if (root == NULL)
    {
        root = newNode(data);
    }
    else if (data >= root->data)
    {
        root->right = insert(root->right, data);
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
    }

    return root;
}

int height(node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);

        if (lheight > rheight)
        {
            return (lheight + 1);
        }
        else
        {
            return (rheight + 1);
        }
    }
}

void currentLevel(node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        currentLevel(root->left, level - 1);
        currentLevel(root->right, level - 1);
    }
}

void levelOrder(node *root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        currentLevel(root, i);
}

void levelOrderQueue(node *root)
{
    if (root == NULL)
        return;
  
    enqueue(&head, root);
 
    while (isEmpty(head, tail) == false) { 
        node* n = dequeue(&head);
        printf("%d ", n->data);
 
        if (n->left != NULL)
            enqueue(&tail, n->left);

        if (n->right != NULL)
            enqueue(&tail, n->right);
    }
}