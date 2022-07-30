#include "dll.h"

int main()
{
    dll *head = NULL;
    int option = 0;

    menu();
    printf("Enter 1 to 8 to choose an action. Any other value to quit.\n");
    scanf("%d", &option);
    getchar(); // to remove \n

    while (option >= 1 && option <= 8)
    {
        switch (option)
        {
        case 1:
            add_at_beg(&head);
            break;
        case 2:
            insert_after(&head);
            break;
        case 3:
            insert_before(&head);
            break;
        case 4:
            append(&head);
            break;
        case 5:
            count(head);
            break;
        case 6:
            delete (&head);
            break;
        case 7:
            search(head);
            break;
        case 8:
            print(head);
            break;
        default:
            break;
        }
        // menu();
        printf("Enter 1 to 8 to choose an action. Any other number to quit.\n");
        fflush(stdin);
        scanf("%d", &option);
        getchar(); // to remove \n
    }

    return 0;
}
