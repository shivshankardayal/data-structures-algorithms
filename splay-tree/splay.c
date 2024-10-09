#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct sp_node {
	void *data;
	struct sp_node *left;
	struct sp_node *right;
} sp_node;

typedef struct sp_tree {
	sp_node *root;
	int (*comp)(const void *, const void *);
} sp_tree;

sp_tree *new_sp_tree(int (*comp)(const void *, const void *));
void *sp_tree_insert(sp_tree *tree, void *data);
void *sp_tree_search(sp_tree *tree, const void *data);
void *sp_tree_remove(sp_tree *tree, const void *data);

sp_tree *new_sp_tree(int (*comp)(const void *, const void *)) {
	assert(comp != NULL);

	sp_tree *tree = (sp_tree *)malloc(sizeof(sp_tree));
	if (tree == NULL) {
		fprintf(stderr, "ERROR: Unable to allocate memory for sp_tree\n");
	}

	else {
		tree->root = NULL;
		tree->comp = comp;
	}

	return tree;
}

// Moves the node with "data" to the root of the splay tree.
// If data is not found moves the last node found in the search path to "data".
//
void splay(sp_tree *tree, const void *data) {

	sp_node root;
	sp_node *left;
	sp_node *right;
	sp_node *node;
	sp_node *temp;
	int comp;

	assert(tree != NULL);
	assert(data != NULL);

	root.right = root.left = NULL;
	left = right = &root;
	node = tree->root;
	if (node == NULL) {
		return;
	}

	for (;;) {
		comp = (tree->comp)(data, node->data);

		if (comp < 0) {
			if (node->left == NULL) {
				break;
			}

			// Rotate right if needed:
			if ((tree->comp)(data, node->left->data) < 0) {
				temp = node->left;
				node->left = temp->right;
				temp->right = node;
				node = temp;
				if (node->left == NULL) {
					break;
				}
			}

			// Link right:
			right->left = node;
			right = node;
			node = node->left;

			// If "data" is bigger:
		} else if (comp > 0) {
			if (node->right == NULL) {
				break;
			}

			// Rotate left if needed:
			if ((tree->comp)(data, node->right->data) > 0) {
				temp = node->right;
				node->right = temp->left;
				temp->left = node;
				node = temp;
				if (node->right == NULL) {
					break;
				}
			}

			// Link left:
			left->right = node;
			left = node;
			node = node->right;

			// If we have found "data":
		} else {
			break;
		}
	}

	// Assemble:
	left->right = node->left;
	right->left = node->right;
	node->left = root.right;
	node->right = root.left;
	tree->root = node;
}

// Moves the node with the smallest element to the root of the splay tree.
void splay_left(sp_tree *tree) {

	sp_node root;
	sp_node *right;
	sp_node *node;
	sp_node *temp;

	assert(tree != NULL);

	root.right = root.left = NULL;
	right = &root;
	node = tree->root;
	if (node == NULL) {
		return;
	}

	for (;;) {

		// Act as if splaying "data" which is always smaller
		if (node->left == NULL) {
			break;
		}

		// Rotate right:
		temp = node->left;
		node->left = temp->right;
		temp->right = node;
		node = temp;
		if (node->left == NULL) {
			break;
		}

		// Link right:
		right->left = node;
		right = node;
		node = node->left;
	}

	// Assemble:
	right->left = node->right;
	node->right = root.left;
	tree->root = node;
}

// Moves the node with the biggest element to the root of the splay tree.
//
static inline void splay_right(sp_tree *tree) {

	sp_node root;
	sp_node *left;
	sp_node *node;
	sp_node *temp;

	assert(tree != NULL);

	root.right = root.left = NULL;
	left = &root;
	node = tree->root;
	if (node == NULL) {
		return;
	}

	for (;;) {

		// Act as if splaying "data" which is always bigger
		if (node->right == NULL) {
			break;
		}

		// Rotate left:
		temp = node->right;
		node->right = temp->left;
		temp->left = node;
		node = temp;
		if (node->right == NULL) {
			break;
		}

		// Link left:
		left->right = node;
		left = node;
		node = node->right;
	}

	// Assemble:
	left->right = node->left;
	node->left = root.right;
	tree->root = node;
}

void *sp_tree_insert(sp_tree *tree, void *data) {

	sp_node *old_root;
	void *old_data;
	int comp = 1;

	assert(tree != NULL);
	assert(data != NULL);

	// Trivial case: Empty tree
	if (tree->root == NULL) {
		tree->root = (sp_node *)malloc(sizeof(sp_node));
		if (tree->root == NULL) {
			fprintf(stderr, "ERROR: Unable to allocate sp_node\n");
		} else {
			tree->root->data = data;
			tree->root->left = NULL;
			tree->root->right = NULL;
		}
		return NULL;
	}

	// General case: Splay data to the root
	splay(tree, data);
	old_root = tree->root;

	// Compare the current root with data:
	if (old_root != NULL) {
		comp = (tree->comp)(data, old_root->data);
	}

	// If data is in the tree: overwrite it!
	if (comp == 0) {
		old_data = tree->root->data;
		tree->root->data = data;
		return old_data;
	}

	// Otherwise insert a new node as a root and link the previous root to it:
	tree->root = (sp_node *)malloc(sizeof(sp_node));
	if (tree->root == NULL) {
		fprintf(stderr, "ERROR: Unable to allocate sp_node\n");
		tree->root = old_root;
	} else {
		tree->root->data = data;
		if (comp > 0) {
			tree->root->left = old_root;
			tree->root->right = old_root->right;
			old_root->right = NULL;
		} else {
			tree->root->right = old_root;
			tree->root->left = old_root->left;
			old_root->left = NULL;
		}
	}

	// Data was not here!
	return NULL;
}

// Finds a node that compares "equal" to data. Returns NULL if not found.
//
void *sp_tree_search(sp_tree *tree, const void *data) {
	assert(tree != NULL);
	assert(data != NULL);

	if (tree->root == NULL) {
		return NULL;
	}

	splay(tree, data);

	// If data is in the tree return a pointer to it:
	if ((tree->comp)(data, tree->root->data) == 0) {
		return tree->root->data;
	}

	return NULL;
}

// Removes a node of tree that compares "equal" to data and returns a pointer
// to the previously stored data (so you can free it).
void *sp_tree_remove(sp_tree *tree, const void *data) {

	sp_node *old_root;
	void *old_data = NULL;

	assert(tree != NULL);
	assert(data != NULL);

	if (tree->root != NULL) {

		// Splay the data to the root:
		splay(tree, data);

		// If it is here: remove it!
		if ((tree->comp)(tree->root->data, data) == 0) {
			old_root = tree->root;
			old_data = tree->root->data;
			if (tree->root->right == NULL) {
				tree->root = tree->root->left;
			} else {
				tree->root = tree->root->right;
				splay_left(tree);
				tree->root->left = old_root->left;
			}
			free(old_root);
		}
	}

	// Return
	return old_data;
}

typedef struct MyData {
	int key;
} MyData;

int sp_tree_is_empty(const sp_tree *tree) {

	// Sanity check:
	assert(tree != NULL);

	// Check if there is at least 1 node in the tree:
	if (tree->root == NULL) {
		return 1;
	} else {
		return 0;
	}
}

int is_sp_subtree(const sp_tree *tree, const sp_node *node, const void *min,
                  const void *max) {

	// Make sure that node is (strictly) between specified limits:
	if (min != NULL && (tree->comp)(min, node->data) >= 0) {
		fprintf(stderr, "ERROR: Symmetric order not satisfied in sp_tree\n");
		return 0;
	}
	if (max != NULL && (tree->comp)(node->data, max) >= 0) {
		fprintf(stderr, "ERROR: Symmetric order not satisfied in sp_tree\n");
		return 0;
	}

	// Check recursively the left subtree of node:
	if (node->left != NULL) {
		if (is_sp_subtree(tree, node->left, min, node->data) == 0) {
			return 0;
		}
	}

	// Check recursively the right subtree of node:
	if (node->right != NULL) {
		if (is_sp_subtree(tree, node->right, node->data, max) == 0) {
			return 0;
		}
	}

	// All test are fine:
	return 1;
}

int is_sp_tree(const sp_tree *tree) {

	// Basic Sanity Checks:
	if (tree == NULL) {
		fprintf(stderr, "ERROR: NULL pointer to sp_tree\n");
		return 0;
	}
	if (tree->comp == NULL) {
		fprintf(stderr, "ERROR: NULL comparing function in sp_tree\n");
		return 0;
	}

	// Trivial Case: empty tree
	if (tree->root == NULL) {
		return 1;
	}

	// General Case:
	return is_sp_subtree(tree, tree->root, NULL, NULL);
}

int comp(const void *ptr1, const void *ptr2) {
	MyData *d1 = (MyData *)ptr1;
	MyData *d2 = (MyData *)ptr2;
	if (d1->key < d2->key) {
		return -1;
	} else if (d1->key > d2->key) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	sp_tree *tree = new_sp_tree(comp);
	MyData *data = NULL;
	MyData *found = NULL;
	int max_size = 10000;

	// It is a sp_tree:
	if (is_sp_tree(tree) == 0) {
		return 1;
	}

	// It is empty:
	if (sp_tree_is_empty(tree) == 0) {
		return 1;
	}

	// Insert elements sequentially in the tree:
	for (int i = 0; i < max_size; i++) {

		data = (MyData *)malloc(sizeof(MyData));
		data->key = i;
		found = sp_tree_insert(tree, data);

		// It was not already there:
		if (found != NULL) {
			return 1;
		}

		// It is a sp_tree:
		if (is_sp_tree(tree) == 0) {
			return 1;
		}

		// It is not empty:
		if (sp_tree_is_empty(tree) == 1) {
			return 1;
		}
	}
}
