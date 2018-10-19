#include "queue.h"

void enqueue(int queue[], int element)
{
  if((head == 0 && tail== MAX-1) || (head==tail+1))
    printf("\n\nQueue is full.\n");
  else
    {
      if(tail == -1)
        {
          tail = 0;
          head = 0;
        }
      else if(tail == MAX - 1)
        tail = 0;
      else
        tail++;
      queue[tail] = element;
    }
}

int dequeue(int queue[])
{
  int element = 0;

  if(head == -1)
    printf("\nQueue is empty.\n");
  else
    {
      element = queue[head];
      if(head == tail)
        {
          head = -1;
          tail = -1;
        }
      else if(head == MAX - 1)
        head = 0;
      else
        head++;
    }
  return element;
}

void menu()
{
  puts("1. Enqueue and element into the queue.");
  puts("2. Dequeque an element from the queue.");
}

int main()
{
  int queue[MAX];
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
          enqueue(queue, element);
          break;
        case 2:
          dequeued_element = dequeue(queue);
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
