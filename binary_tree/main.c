#include <stdio.h>
#include "binary_tree.h"

int main()
{
    node *root = NULL;
    int option = -1;
    int data = 0;

    // event-loop.
    while (option != 0)
    {
        printf(
            "\n\n1. Insert a Node\n2. Delete a Node\n3. Find a Node\n0. Quit\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter the new node's value:\n");
            scanf("%d", &data);
            root = insert(root, data);
            break;

        case 2:
            printf("Enter the value to be removed:\n");
            if (root != NULL)
            {
                scanf("%d", &data);
                root = delete (root, data);
            }
            else
            {
                printf("Tree is already empty!\n");
            }
            break;

        case 3:
            printf("Enter the searched value:\n");
            scanf("%d", &data);
            find(root, data) ? printf("The value is in the tree.\n")
                             : printf("The value is not in the tree.\n");
            break;
        }
    }

    return 0;
}
