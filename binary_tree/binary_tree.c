#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

node* new_node(int data)
{
    node *temp = (node *)malloc(sizeof(node));

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

node* insert(node *root, int data)
{
    if (root == NULL)
    {
        root = new_node(data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else if (data < root->data)
    {
        root->left = insert(root->left, data);
    }

    return root;
}

node* get_max(node *root)
{
    if (root->right != NULL)
    {
        return get_max(root->right);
    }
    return root;
}

node* delete (node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if (data > root->data)
    {
        root->right = delete (root->right, data);
    }
    else if (data < root->data)
    {
        root->left = delete (root->left, data);
    }
    else if (data == root->data)
    {
        if ((root->left == NULL) && (root->right == NULL))
        {  // Case 1: the root has no leaves so delete the node
            free(root);
            return NULL;
        }
        else if (root->left == NULL)
        {  // Case 2: the root has one leaf, make the leaf the new root and
            // delete the old root
            node* temp = root;
            root = root->right;
            free(temp);
            return root;
        }
        else if (root->right == NULL)
        {
            node* temp = root;
            root = root->left;
            free(temp);
            return root;
        }
        else
        {  // Case 3: the root has 2 leaves, find the greatest key in the left
            // subtree and switch with the root. alternatively minimum in the
            // right subtree can be found and used

            node* temp = get_max(root->left);

            // sets the data of this node equal to the data of the biggest node
            // (lefts)
            root->data = temp->data;
            root->left = delete (root->left, temp->data);
        }
    }
    return root;
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
