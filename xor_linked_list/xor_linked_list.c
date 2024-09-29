#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct node {
    int data;
    struct node* both;
} Node;

Node* XOR(Node* a, Node* b)
{
    if(a == NULL) {
        a = 0;
    }

    if (b == NULL) {
        b = 0;
    }

    return (Node*)((size_t)a^(size_t)b);
}

void insert_at_head(Node** head, Node** tail, int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->both = XOR(NULL, *head);

    if (*head) {
        (*head)->both
            = XOR(new_node, XOR((*head)->both, NULL));
    }
    else {
        *tail = new_node;
    }
    
    *head = new_node;
}

void insert_at_tail(Node** head, Node** tail, int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->both = XOR(*tail, NULL);

    if (*tail) {
        (*tail)->both
            = XOR(XOR((*tail)->both, NULL), new_node);
    }
    else {
        *head = new_node;
    }

    *tail = new_node;
}

void delete_from_head(Node** head, Node** tail)
{
    if (*head) {
        Node* next = XOR((*head)->both, NULL);
        Node* tmp = *head;
        free(*head);
        *head = next;

        if (next) {
            next->both = XOR(XOR(next->both, tmp), NULL);
        }
        else {
            *tail = NULL;
        }
    }
}

void delete_from_tail(Node** head, Node** tail)
{
    if (*tail) {
        Node* prev = XOR((*tail)->both, NULL);
        Node* tmp = *tail;
        free(*tail);
        *tail = prev;

        if (prev) {
            prev->both = XOR(XOR(prev->both, tmp), NULL);
        }
        else {
            *head = NULL;
        }
    }
}

void print_list(Node* head)
{
    Node* current = head;
    Node* prev = NULL;
    while (current) {
        printf("%d ", current->data);
        Node* next = XOR(prev, current->both);
        prev = current;
        current = next;
    }
    
    printf("\n");
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    insert_at_head(&head, &tail, 10);
    insert_at_head(&head, &tail, 20);
    insert_at_tail(&head, &tail, 30);
    insert_at_tail(&head, &tail, 40);
    // prints 20 10 30 40
    print_list(head);
    delete_from_head(&head, &tail);
    // prints 10 30 40
    print_list(head);
    delete_from_tail(&head, &tail);
    // prints 10 30
    print_list(head);

    return 0;
}
