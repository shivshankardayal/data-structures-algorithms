#include "stack.h"

bool isEmpty()
{
  printf("top is %d\n", top);
  if(top < 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void push(int stack[], int element)
{
  if(top >= MAX - 1)
  {
    printf("Stack overflow.\n");
    return;
  }
  else
  {
    stack[++top] = element;
    printf("Pushed element is %d.\n", element);
  }
}

int pop(int stack[])
{
  if(isEmpty(stack))
  {
    printf("Stack underflow.\n");
    exit(-1);
  }
  else
  {
    int x = stack[top];
    --top;
    return x;
  }
}

void menu()
{
  puts("1. Push an element on top of stack.");
  puts("2. Pop an element off the top of stack.");
}

int main()
{
  int stack[MAX];
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
      push(stack, element);
      break;
    case 2:
      popped_element = pop(stack);
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
