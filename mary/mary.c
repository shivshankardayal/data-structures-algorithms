#include <stdio.h>
#include <stdlib.h>

// Define maximum number of children for each node
#define MAXCHILDREN 3

// Define a structure for an m-ary tree node
typedef struct TreeNode {
    int data;
    struct TreeNode* children[MAXCHILDREN];
} TreeNode;

// Create a new tree node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;

    // Initialize all children as NULL
    for (int i = 0; i < MAXCHILDREN; i++) {
        newNode->children[i] = NULL;
    }

    return newNode;
}

// Add a child to a node (first empty slot)
void addChild(TreeNode* parent, TreeNode* child) {
    for (int i = 0; i < MAXCHILDREN; i++) {
        if (parent->children[i] == NULL) {
            parent->children[i] = child;
            return;
        }
    }
    printf("Node %d has no empty child slots!\n", parent->data);
}

// Preorder Traversal (Root -> Children)
void preorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    // Process the current node
    printf("%d ", root->data);

    // Traverse all children
    for (int i = 0; i < MAXCHILDREN; i++) {
        preorderTraversal(root->children[i]);
    }
}

// Inorder Traversal (Generalized for m-ary trees)
void inorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    // Traverse the leftmost children first
    if (MAXCHILDREN > 0 && root->children[0] != NULL) {
        inorderTraversal(root->children[0]);
    }

    // Process the current node
    printf("%d ", root->data);

    // Traverse remaining children
    for (int i = 1; i < MAXCHILDREN; i++) {
        if (root->children[i] != NULL) {
            inorderTraversal(root->children[i]);
        }
    }
}

// Postorder Traversal (Children -> Root)
void postorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    // Traverse all children first
    for (int i = 0; i < MAXCHILDREN; i++) {
        postorderTraversal(root->children[i]);
    }

    // Process the current node
    printf("%d ", root->data);
}

// Delete a subtree starting from a specific node
void deleteSubtree(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    // Recursively delete all children
    for (int i = 0; i < MAXCHILDREN; i++) {
        deleteSubtree(root->children[i]);
    }

    // Free the current node
    printf("Deleting node %d\n", root->data);
    free(root);
}

// Main function to demonstrate the m-ary tree
int main() {
    // Create root node
    TreeNode* root = createNode(1);

    // Add children to root
    TreeNode* child1 = createNode(2);
    TreeNode* child2 = createNode(3);
    TreeNode* child3 = createNode(4);
    addChild(root, child1);
    addChild(root, child2);
    addChild(root, child3);

    // Add children to child1
    TreeNode* child4 = createNode(5);
    TreeNode* child5 = createNode(6);
    addChild(child1, child4);
    addChild(child1, child5);
    // now the tree looks like
    /*             1
                /  |  \
              2    3    4
             / \
            5   6
    */

    // Display traversals
    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");

    // Free the entire tree
    deleteSubtree(root);

    return 0;
}

