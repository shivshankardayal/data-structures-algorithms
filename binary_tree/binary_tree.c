#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

unsigned int max(unsigned int a, unsigned int b)
{
    return a > b ? a : b;
}

node *newNode(int data, node *lft, node *rgt)
{
    node *temp = (node *)malloc(sizeof(node));

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1 + max(ht(lft), ht(rgt));

    return temp;
}

unsigned int ht(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return root->height;
    }
}

void installHeight(node *root)
{
    root->height = 1 + max(ht(root->left), ht(root->right));
}

node* insert(node* root, int data)
{
    if (root == NULL)
    {
        root = newNode(data, NULL, NULL);
    }
    else if (data >= root->data)
    {
        root->right = insert(root->right, data);
        rebalance(&(root->right));
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
        rebalance(&(root->left));
    }

    return root;
}

node *getMax(node *root)
{
    if (root->right != NULL)
    {
        return getMax(root->right);
    }
    return root;
}

void rebalance(node **root)
{
    int hl = ht((*root)->left);
    int hr = ht((*root)->right);

    if (hr > hl + 1)
    {
        rotateLeft(root);
    }
    else if (hl > hr + 1)
    {
        rotateRight(root);
    }
    else
    {
        installHeight(*root);
    }
}

void rotateRight(node **root)
{
    node *L = (*root)->left;
    int zig = ht(L->left);
    int zag = ht(L->right);

    if (zig > zag)
    {
        singleRotateRight(root);
    }
    else
    {
        doubleRotateRight(root);
    }
}

void rotateLeft(node **root)
{
    node *r = (*root)->right;
    int zag = ht(r->left);
    int zig = ht(r->right);

    if (zig > zag)
    {
        singleRotateLeft(root);
    }
    else
    {
        doubleRotateLeft(root);
    }
}

void doubleRotateRight(node **root)
{
    singleRotateLeft(&(*root)->left);
    singleRotateRight(root);
}

void doubleRotateLeft(node **root)
{
    singleRotateRight(&(*root)->right);
    singleRotateLeft(root);
}

void singleRotateRight(node **root)
{
    node *L = (*root)->left;
    (*root)->left = L->right;
    installHeight(*root);

    L->right = *root;
    *root = L;
    installHeight(*root);
}

void singleRotateLeft(node **root)
{
    node *r = (*root)->right;
    (*root)->right = r->left;
    installHeight(*root);

    r->left = *root;
    *root = r;
    installHeight(*root);
}

node* delete (node **root, int data)
{
    if (*root == NULL)
    {
        return *root;
    }
    else if (data > (*root)->data)
    {
        (*root)->right = delete (&(*root)->right, data);
        rebalance(root);
    }
    else if (data < (*root)->data)
    {
        (*root)->left = delete (&(*root)->left, data);
        rebalance(root);
    }
    else if (data == (*root)->data)
    {
        if (((*root)->left == NULL) && ((*root)->right == NULL))
        { // Case 1: the root has no leaves so delete the node
            free(*root);
            return NULL;
        }
        else if ((*root)->left == NULL)
        { // Case 2: the root has one leaf, make the leaf the new root and
            // delete the old root
            node *temp = *root;
            *root = (*root)->right;
            free(temp);
            return *root;
        }
        else if ((*root)->right == NULL)
        {
            node *temp = *root;
            *root = (*root)->left;
            free(temp);
            return *root;
        }
        else
        { // Case 3: the root has 2 leaves, find the greatest key in the left
            // subtree and switch with the root. alternatively minimum in the
            // right subtree can be found and used

            node *temp = getMax((*root)->left);

            // sets the data of this node equal to the data of the biggest node
            // (lefts)
            (*root)->data = temp->data;
            (*root)->left = delete (&(*root)->left, temp->data);
            rebalance(root);
        }
    }
    return *root;
}

int find(node *root, int data)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (data > root->data)
    {
        return find(root->right, data);
    }
    else if (data < root->data)
    {
        return find(root->left, data);
    }
    else if (data == root->data)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void preorder(node *root)
{
    if (root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
