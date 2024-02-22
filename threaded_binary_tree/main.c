#include "tbt.h"

// Single Threaded: Where a NULL right pointers is point to the inorder successor if successor exists
// Double Threaded: Where both left and right NULL pointers are point to inorder predecessor and
// inorder successor respectively.

// Advantages:

// makes linear traversal of elements possible.
// eliminates the use of stack because of linear traversal.
// possible to find parent node without explicit use of parent pointer
// forward and backward traversal of nodes in an inorder way
// searching is easier we can easily find inorder predecessor and successor.
// finding predecessor and successor nodes of any node is fast.

// Disadvantages:

// extra memory needed in each node so memory conumption is higher
// insertion and deletions are complex and hence time consuming
// less flexibility

// Applications:

// Expression evaluation, database indexing, symbol table management, disk based data strutures

// driver for threaded binary tree
int main()
{
    Node* root = NULL;

    root = insert(root, 40);
    root = insert(root, 20);
    root = insert(root, 60);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 8);

    inorder(root);
    root = delete(root, 40);
    inorder(root);
		root = delete(root, 8);
		inorder(root);
		root = delete(root, 60);
		inorder(root);
		root = delete(root, 70);
		inorder(root);

    return EXIT_SUCCESS;
}
