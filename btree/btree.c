#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define T 3 // Minimum degree

// B-Tree Node Definition
typedef struct BTreeNode {
    int *keys;                 // Array of keys
    struct BTreeNode **children; // Array of child pointers
    int n;                     // Current number of keys
    bool isLeaf;               // Leaf indicator
} BTreeNode;

// Create a new BTreeNode
BTreeNode* createNode(bool isLeaf) {
    BTreeNode *node = (BTreeNode *)malloc(sizeof(BTreeNode));
    node->keys = (int *)malloc((2 * T - 1) * sizeof(int));
    node->children = (BTreeNode **)malloc((2 * T) * sizeof(BTreeNode *));
    node->n = 0;
    node->isLeaf = isLeaf;
    return node;
}

// Traversal of the B-tree
void traverse(BTreeNode *node) {
    if (node == NULL) return;

    for (int i = 0; i < node->n; i++) {
        if (!node->isLeaf)
            traverse(node->children[i]);
        printf("%d ", node->keys[i]);
    }

    if (!node->isLeaf)
        traverse(node->children[node->n]);
}

// Search key in B-tree
BTreeNode* search(BTreeNode *node, int key) {
    int i = 0;
    while (i < node->n && key > node->keys[i])
        i++;

    if (i < node->n && node->keys[i] == key)
        return node;

    if (node->isLeaf)
        return NULL;

    return search(node->children[i], key);
}

// Split the child of a node
void splitChild(BTreeNode *parent, int i, BTreeNode *child) {
    BTreeNode *newNode = createNode(child->isLeaf);
    newNode->n = T - 1;

    for (int j = 0; j < T - 1; j++)
        newNode->keys[j] = child->keys[j + T];

    if (!child->isLeaf) {
        for (int j = 0; j < T; j++)
            newNode->children[j] = child->children[j + T];
    }

    child->n = T - 1;

    for (int j = parent->n; j >= i + 1; j--)
        parent->children[j + 1] = parent->children[j];

    parent->children[i + 1] = newNode;

    for (int j = parent->n - 1; j >= i; j--)
        parent->keys[j + 1] = parent->keys[j];

    parent->keys[i] = child->keys[T - 1];
    parent->n += 1;
}

// Insert non-full node
void insertNonFull(BTreeNode *node, int key) {
    int i = node->n - 1;

    if (node->isLeaf) {
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->n += 1;
    } else {
        while (i >= 0 && key < node->keys[i])
            i--;

        if (node->children[i + 1]->n == 2 * T - 1) {
            splitChild(node, i + 1, node->children[i + 1]);

            if (key > node->keys[i + 1])
                i++;
        }
        insertNonFull(node->children[i + 1], key);
    }
}

// Insert key into the B-tree
BTreeNode* insert(BTreeNode *root, int key) {
    if (root == NULL) {
        root = createNode(true);
        root->keys[0] = key;
        root->n = 1;
        return root;
    }

    if (root->n == 2 * T - 1) {
        BTreeNode *newRoot = createNode(false);
        newRoot->children[0] = root;
        splitChild(newRoot, 0, root);

        int i = (newRoot->keys[0] < key) ? 1 : 0;
        insertNonFull(newRoot->children[i], key);
        return newRoot;
    }

    insertNonFull(root, key);
    return root;
}

// Merge children of a node
void merge(BTreeNode *node, int idx) {
    BTreeNode *child = node->children[idx];
    BTreeNode *sibling = node->children[idx + 1];

    child->keys[T - 1] = node->keys[idx];

    for (int i = 0; i < sibling->n; ++i)
        child->keys[i + T] = sibling->keys[i];

    if (!child->isLeaf) {
        for (int i = 0; i <= sibling->n; ++i)
            child->children[i + T] = sibling->children[i];
    }

    for (int i = idx + 1; i < node->n; ++i)
        node->keys[i - 1] = node->keys[i];

    for (int i = idx + 2; i <= node->n; ++i)
        node->children[i - 1] = node->children[i];

    child->n += sibling->n + 1;
    node->n--;

    free(sibling->keys);
    free(sibling->children);
    free(sibling);
}

// Delete a key from the subtree rooted at the node
void deleteKey(BTreeNode *node, int key) {
    int idx = 0;
    while (idx < node->n && node->keys[idx] < key)
        ++idx;

    if (idx < node->n && node->keys[idx] == key) {
        if (node->isLeaf) {
            for (int i = idx + 1; i < node->n; ++i)
                node->keys[i - 1] = node->keys[i];
            node->n--;
        } else {
            BTreeNode *pred = node->children[idx];
            if (pred->n >= T) {
                int predKey = pred->keys[pred->n - 1];
                node->keys[idx] = predKey;
                deleteKey(pred, predKey);
            } else {
                BTreeNode *succ = node->children[idx + 1];
                if (succ->n >= T) {
                    int succKey = succ->keys[0];
                    node->keys[idx] = succKey;
                    deleteKey(succ, succKey);
                } else {
                    merge(node, idx);
                    deleteKey(pred, key);
                }
            }
        }
    } else {
        if (node->isLeaf) {
            printf("Key %d not found\n", key);
            return;
        }

        bool flag = (idx == node->n);

        if (node->children[idx]->n < T)
            merge(node, idx);

        if (flag && idx > node->n)
            deleteKey(node->children[idx - 1], key);
        else
            deleteKey(node->children[idx], key);
    }
}

// Driver Code
int main() {
    BTreeNode *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 12);
    root = insert(root, 30);
    root = insert(root, 7);
    root = insert(root, 17);

    BTreeNode *node = search(root, 12);
    if(node) {
        printf("key 12 found\n");
    }

    printf("Traversal of the tree:\n");
    traverse(root);
    printf("\n");

    printf("Deleting 6\n");
    deleteKey(root, 6);
    traverse(root);
    printf("\n");

    printf("Deleting 13\n");
    deleteKey(root, 13);
    traverse(root);
    printf("\n");

    printf("Deleting 7\n");
    deleteKey(root, 7);
    traverse(root);
    printf("\n");

    return 0;
}

