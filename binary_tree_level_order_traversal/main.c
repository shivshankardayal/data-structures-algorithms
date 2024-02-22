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
            "\n\n1. Insert a Node\n2. Level Order Traversal\
\n3. Level order traversal using queue\n0. Quit\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("Enter the new node's value:\n");
            scanf("%d", &data);
            root = insert(root, data);
            break;

        case 2:
            printf("Perform level order traversal:\n");
            if (root != NULL)
            {
                levelOrder(root);
            }
            else
            {
                printf("Tree is empty!\n");
            }
            break;
        case 3:
            printf("Perform level order traversal using queue:\n");
            if (root != NULL)
            {
                levelOrderQueue(root);
            }
            else
            {
                printf("Tree is empty!\n");
            }
            break;
        default:
            break;
        }
    }

    return 0;
}
