#include "cll.h"

void delete (cll **head)
{
    cll *temp, *q;
    int i;

    temp = *head;

    if (*head == NULL)
    {
        printf("There is no element to be deleted.\n");
        return;
    }

    printf("Enter the value of data to be deleted.\n");
    scanf("%d", &i);

    if (temp->data == i)
    {
        if (temp == temp->next)
        { // there is only one node
            free(temp);
            *head = NULL;
            return;
        }

        cll *to_delete = temp;
        while (temp->next != *head)
            temp = temp->next;
        *head = temp->next->next;
        temp->next = temp->next->next;
        free(to_delete);
        return;
    }
    else
    {
        while (temp->next != *head)
        {
            if (temp->data == i)
            {
                q->next = temp->next;
                free(temp);
                return;
            }
            q = temp;
            temp = temp->next;
        }
    }

    if (temp->data == i)
    { // case of deletion of last node
        q->next = temp->next;
        free(temp);
        return;
    }

    printf("The element to be deleted was not found.\n");
}

int count(cll *head)
{
    int count = 1;

    if (head == NULL)
    {
        printf("The no. of elements in linked list is %d.\n", 0);
        return 0;
    }

    while (head->next != NULL)
    {
        count++;
        head = head->next;
    }

    printf("The no. of elements in linked list is %d.\n", count);
    return count;
}

void menu()
{
    puts("1. Add an element at beginning.");
    puts("2. Add an element at position n.");
    puts("3. Add an element at end.");
    puts("4. Count the number of elements.");
    puts("5. Delete an element.");
    puts("6. Search an element.");
    puts("7. Print the list.");
}

void append(cll **head)
{
    cll *temp, *q = *head;
    int i;

    printf("Enter the number which is to be appended to the list.\n");
    scanf("%d", &i);

    temp = (cll *)malloc(sizeof(cll));
    temp->data = i;
    temp->next = NULL;

    if (!(*head))
    {
        *head = temp;
        temp->next = temp;
        return;
    }

    while (q->next != *head)
    {
        q = q->next;
    }

    q->next = temp;
    temp->next = *head;
}

void add_in_bet(cll **head)
{
    cll *temp, *q = *head;
    int i = 0, j = 0;
    int position = 0;

    printf("Enter position at which the number is to be added.\n");
    scanf("%d", &position);

    if (position == 0)
        return add_at_beg(head);

    temp = (cll *)malloc(sizeof(cll));

    printf("Enter an integer to be added in between.\n");
    scanf("%d", &i);

    while (q->next != *head)
    {
        ++j;
        if (j == position)
        {
            temp->next = q->next;
            q->next = temp;
            temp->data = i;
            return;
        }
        q = q->next;
    }
    ++j;
    // This is the case when q->next is *head so it is an append
    // operation
    if (j == position)
    {
        append(head);
    }
    free(temp); // no insertion happened so we need to free temp
                // i.e. j was out of possible positions
}

void add_at_beg(cll **head)
{
    cll *temp = *head;
    int i;
    cll *it = NULL; // iterator pointer

    it = (cll *)malloc(sizeof(cll));

    printf("Enter an integer to be added at beginning\n");
    scanf("%d", &i);

    it->data = i;
    it->next = *head;

    if (*head != NULL)
    {
        while (temp->next != *head)
            temp = temp->next;
        temp->next = it;
    }
    else
    {
        it->next = it;
    }
    *head = it;
}

void print(cll *head)
{
    cll *first = head;

    if (!head)
        return;

    do
    {
        printf("%d--->", head->data);
        head = head->next;
    } while (head != first);

    printf("head\n");
}

void search(cll *head)
{
    int i = 0, position = 1;
    cll *first = head;

    if (!head) // list is empty
        return;

    printf("Enter the number to be searched.");
    scanf("%d", &i);

    do
    {
        if (head->data == i)
        {
            printf("%d is found at position %dth\n", i, position);
            return;
        }
        head = head->next;
        position++;
    } while (head != first);
    printf("%d was not found in linked list.\n", i);
}
