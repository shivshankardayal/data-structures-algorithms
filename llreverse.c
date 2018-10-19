#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list {
    int data;
    struct linked_list *next;
}ll;

void menu();
void add_at_beg(ll**);
void print(ll*);
void search(ll*);
void delete(ll**);
void append(ll**);
void add_in_bet(ll**);
void reverse(ll**);

void reverse(ll** head)
{
    ll *next = NULL;
    ll *current = NULL;

    if(!(*head))
        return;

    while((*head)->next != NULL)
    {
        next = (*head)->next;
        (*head)->next = current;
        current = *head;
        (*head) = next;
    }
    (*head)->next = current;
}

void delete(ll** head)
{
    ll *temp, *q;
    int i;

    temp = *head;

    if(*head == NULL) {
        printf("There is no element to be deleted.\n");
        return;
    }

    printf("Enter the value of data to be deleted.\n");
    scanf("%d", &i);

    if(temp->data == i) {
        *head = temp->next;
        free(temp);
        return;
    } else {
        while(temp->next != NULL) {
            if(temp->data == i) {
                q->next = temp->next;
                free(temp);
                return;
            }
            q = temp;
            temp = temp->next;
        }
    }

    if(temp->data == i) { // case of deletion of last node
        q->next = temp->next;
        free(temp);
        return;
    }

    printf("The element to be deleted was not found.\n");
}

int count(ll* head)
{
    int count = 1;

    if(head == NULL) {
        printf("The no. of elements in linked list is %d.\n", 0);
        return 0;
    }

    while(head->next != NULL) {
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
    puts("7. Reverse the list.");
}

void append(ll** head)
{
    ll* temp, *q = *head;
    int i;

    printf("Enter the number which is to be appended to the list.\n");
    scanf("%d", &i);

    temp = (ll*)malloc(sizeof(ll));
    temp->data = i;
    temp->next = NULL;

    if(!(*head)) {
        *head=temp;
        return;
    }

    while(q->next != NULL) {
        q = q->next;
    }

    q->next = temp;
}

void add_in_bet(ll** head)
{
    ll *temp, *q = *head;
    int i = 0, j = 0;
    int position = 0;

    printf("Enter position at which the number is to be added.\n");
    scanf("%d", &position);

    if(position == 0) {
        add_at_beg(head);
    	return;
    }

    temp = (ll*)malloc(sizeof(ll));

    printf("Enter an integer to be added in between.\n");
    scanf("%d", &i);

    while(q->next != NULL) {
        ++j;
        if(j == position) {
            temp->next = q->next;
            q->next = temp;
            temp->data = i;
            return;
        }
        q = q->next;
    }
    ++j;
    // This is the case when q->next is NULL so it is an append
    // operation
    if(j == position) {
        append(head);
    }
    free(temp); // no insertion happened so we need to free temp
                // i.e. j was out of possible positions
}

void add_at_beg(ll** head)
{
    ll *temp;
    int i;

    temp = (ll*)malloc(sizeof(ll));

    printf("Enter an integer to be added at beginning\n");
    scanf("%d", &i);

    temp->next = *head;
    *head = temp;
    (*head)->data = i;
}

void print(ll* head)
{
    printf("Head-->");
    while(head != NULL) {
        printf("%d--->", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

void search(ll* head)
{
    int i=0, position=1;

    printf("Enter the number to be searched.");
    scanf("%d", &i);

    while(head != NULL) {
        if(head->data == i) {
            printf("%d is found at %dth position.\n", i, position - 1);
            return;
        }

        head = head->next;
        position++;
    }
    printf("%d was not found in linked list.\n", i);
}

int main()
{
    ll* head = NULL;
    int option = 0;

    menu();
    printf("Enter 1 to 8 to choose an action. Any other number to quit.\n");
    scanf("%d", &option);
    getchar(); // to remove \n

    while(option  >= 1 && option <= 8) {
        switch(option) {
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
                delete(&head);
                break;
            case 6:
                search(head);
                break;
            case 7:
                print(head);
                break;
            case 8:
                reverse(&head);
                break;
            default:
                break;
        }
        menu();
        printf("Enter 1 to 8 to choose an action. Any other number to quit.\n");
        fflush(stdin);
        scanf("%d", &option);
        getchar(); // to remove \n
    }

    return 0;
}

