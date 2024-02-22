#include "tbt.h"

Node *insert(Node *root, int data)
{
    Node *node = root;
    Node *parent = NULL; // Parent of node which will contain data

    while (node != NULL)
    {
        // duplicate data case so return
        if (data == (node->data))
        {
            printf("Duplicate Key !\n");
            return root;
        }

        parent = node; // node becomes parent pointer

        if (data < node->data)
        {
            if (node->lthread == false)
                node = node->left;
            else
                break;
        }
        else
        {
            if (node->rthread == false)
                node = node->right;
            else
                break;
        }
    }

    Node *temp = (Node *)malloc(sizeof(Node));     // 40
    temp->data = data;                          //   /
    temp->lthread = true;                      //   20
    temp->rthread = true;                          //
			                                        //  10
    if (parent == NULL)
    {
        root = temp;
        temp->left = NULL;
        temp->right = NULL;
    }
    else if (data < (parent->data))
    {
        temp->left = parent->left;
        temp->right = parent;
        parent->lthread = false;
        parent->left = temp;
    }
    else
    {
        temp->left = parent;
        temp->right = parent->right;
        parent->rthread = false;
        parent->right = temp;
    }

    return root;
}

Node *inorder_successor(Node *node)
{
    // rthread is set, so we can quickly find it
    if (node->rthread == true)
        return node->right;

    // return leftmost child of right subtree
    node = node->right;
    while (node->lthread == false)
        node = node->left;
    return node;
}

void inorder(Node *root)
{
    if (root == NULL)
        printf("Empty tree");

    Node *node = root;
    while (node->lthread == false)
        node = node->left;

    while (node != NULL)
    {
        printf("%d ", node->data);
        node = inorder_successor(node);
    }
    printf("\n");
}

Node *inorder_predecessor(Node *node)
{
    if (node->lthread == true)
        return node->left;

    node = node->left;
    while (node->rthread == false)
        node = node->right;
    return node;
}

Node *delete_no_child(Node *root, Node *parent, Node *node)
{
    if (parent == NULL)
        root = NULL;
    else if (node == parent->left)
    {
        parent->lthread = true;
        parent->left = node->left;
    }
    else
    {
        parent->rthread = true;
        parent->right = node->right;
    }

    free(node);
    return root;
}

Node *delete_one_child(Node *root, Node *parent, Node *node)
{
    Node *child;

    // initialize child in case node to be deleted has
    // left child.
    if (node->lthread == false)
    {
        child = node->left;
    }
    else
    { // node to be deleted has right child.

        child = node->right;
    }

    if (parent == NULL)
    {
        root = child;
    }
    else if (node == parent->left)
    {
        parent->left = child;
    }
    else
    {
        parent->right = child;
    }

    Node *succ = inorder_successor(node);
    Node *pred = inorder_predecessor(node);

    // node has left subtree.
    if (node->lthread == false)
        pred->right = succ;

    // node has right subtree.
    else
    {
        if (node->rthread == false)
            succ->left = pred;
    }

    free(node);
    return root;
}

Node *delete_both_children(Node *root, Node *node)
{
    Node *parsucc = node;
    Node *succ = node->right;

    // leftmost child of successor
    while (succ->lthread == false)
    {
        parsucc = succ;
        succ = succ->left;
    }

    node->data = succ->data;

    if (succ->lthread == true && succ->rthread == true)
        root = delete_no_child(root, parsucc, succ);
    else
        root = delete_one_child(root, parsucc, succ);

    return root;
}

Node *delete(Node *root, int data)
{
    Node *par = NULL, *node = root;

    bool found = false;

    while (node != NULL)
    {
        if (data == node->data)
        {
            found = true;
            break;
        }
        par = node;
        if (data < node->data)
        {
            if (node->lthread == false)
                node = node->left;
            else
                break;
        }
        else
        {
            if (node->rthread == false)
                node = node->right;
            else
                break;
        }
    }

    if (found == false)
        printf("data not present in the tree\n");

    else if (node->lthread == false && node->rthread == false)
        root = delete_both_children(root, node);

    else if (node->lthread == false)
        root = delete_one_child(root, par, node);

    else if (node->rthread == false)
        root = delete_one_child(root, par, node);
    else
        root = delete_no_child(root, par, node);

    return root;
}
