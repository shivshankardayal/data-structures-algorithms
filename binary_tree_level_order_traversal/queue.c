#include "queue.h"

void enqueue(Queue **t, node *n)
{
    Queue *temp = (Queue *)malloc(sizeof(Queue));

    if (temp == NULL)
    {
        printf("Out of memory!\n");
        exit(-1);
    }

    temp->next = NULL;
    temp->n = n;

    if ((head == NULL) && (*t == NULL))
    {
        head = *t = temp;
    }
    else
    {
        (*t)->next = temp;
        *t = temp;
    }
}

node *dequeue(Queue **h)
{
    if (*h == NULL && tail == NULL)
    {
        printf("Queue empty!\n");
        return NULL;
    }

    if ((*h != NULL) && (tail != NULL) && (*h == tail))
    {
        node* n = (*h)->n;
        free(*h);
        *h = tail = NULL;
        return n;
    }
    else
    {
        Queue *temp = *h;

        node* n = (*h)->n;
        *h = (*h)->next;
        free(temp);
        return n;
    }
}

bool isEmpty(Queue *h, Queue *t)
{
    if (h == NULL && t == NULL)
        return true;
    else
        return false;
}