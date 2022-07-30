#include "cll.h"

int main()
{
    cll *head = NULL;
    int option = 0;

    menu();
    printf("Enter 1 to 7 to choose an action. Any other number to quit.\n");
    scanf("%d", &option);
    getchar(); // to remove \n

    while (option >= 1 && option <= 7)
    {
        switch (option)
        {
        case 1:
            add_at_beg(&head);
            break;
        case 2:
            add_in_bet(&head);
            break;
        case 3:
            append(&head);
            break;
        case 4:
            count(head);
            break;
        case 5:
            delete (&head);
            break;
        case 6:
            search(head);
            break;
        case 7:
            print(head);
            break;
        default:
            break;
        }
        menu();
        printf("Enter 1 to 7 to choose an action. Any other number to quit.\n");
        fflush(stdin);
        scanf("%d", &option);
        getchar(); // to remove \n
    }

    return 0;
}
