#include "stack_ll.h"

bool isEmpty(Stack *top)
{
  if(top == NULL)
  {
    return true;
  }
  else
  {
    printf("top is %d\n", top->data);
    return false;
  }
}

void push(Stack** top, int element)
{
  Stack* temp = (Stack*)malloc(sizeof(Stack));

  if(temp == NULL)
  {
    printf("Cannot allocate memory\n");
    exit(1);
  }

  if(top != NULL)
  {
    temp->next = *top;
    *top = temp;
    (*top)->data = element;
  }
  else
  {
    *top = temp;
    (*top)->next = NULL;
    (*top)->data = element;
  }
}

int pop(Stack** top)
{
  if(isEmpty(*top))
  {
    printf("Stack underflow.\n");
    exit(-1);
  }

  Stack* temp = *top;

  *top = (*top)->next;
  int data = temp->data;
  free(temp);
  return data;
}

void menu()
{
  puts("1. Push an element on top of stack.");
  puts("2. Pop an element off the top of stack.");
}

int main()
{
  Stack* stack = NULL;
  int popped_element=0, element=0, option=-1;

  menu();
  printf("Enter 1 or 2 to choose an action. 0 to quit.\n");
  scanf("%d", &option);
  fflush(stdin);
  while(option == 1 || option == 2)
  {
    switch(option)
    {
    case 1:
      printf("Enter an integer to push onto stack.\n");
      scanf("%d", &element);
      push(&stack, element);
      break;
    case 2:
      popped_element = pop(&stack);
      printf("Popped element is %d\n", popped_element);
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
