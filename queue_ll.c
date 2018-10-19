#include "queue_ll.h"

void enqueue(Queue** t, int data)
{
  Queue *temp = (Queue*)malloc(sizeof(Queue));

  if(temp == NULL)
  {
    printf("Out of memory!\n");
    exit(-1);
  }

  temp->next = NULL;
  temp->data = data;

  if((head == NULL) && (*t == NULL))
  {
    head = *t = temp;
  }
  else
  {
    (*t)->next = temp;
    *t = temp;
  }
}

int dequeue(Queue** h)
{
  if(*h == NULL && tail == NULL)
  {
    printf("Queue empty!\n");
    return -1;
  }

  if((*h != NULL) && (tail != NULL) && (*h == tail))
  {
    int data;

    data = (*h)->data;
    free(*h);
    *h = tail = NULL;
    return data;
  }
  else
  {
    int data;
    Queue* temp = *h;

    data = (*h)->data;
    *h = (*h)->next;
    free(temp);
    return data;
  }
}

void menu()
{
  puts("1. Enqueue and element into the queue.");
  puts("2. Dequeque an element from the queue.");
}

int main()
{
  int dequeued_element=0, element=0, option=-1;

  menu();
  printf("Enter 1 or 2 to choose an action. 0 to quit.\n");
  scanf("%d", &option);
  fflush(stdin);
  while(option == 1 || option == 2)
  {
    switch(option)
    {
    case 1:
      printf("Enter an integer to enqueue into queue.\n");
      scanf("%d", &element);
      enqueue(&tail, element);
      break;
    case 2:
      dequeued_element = dequeue(&head);
      printf("Dequeued element is %d\n", dequeued_element);
      break;
    default:
      break;
    }

    menu();
    printf("Enter 1 or 2 to choose an action. 0 to quit.\n");
    fflush(stdin);
    scanf("%d", &option);
    fflush(stdin);
  }

  return 0;
}
