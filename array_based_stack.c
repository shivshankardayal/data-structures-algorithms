#include <stdio.h>
#include <stdlib.h>

const int MAX=8;

// arguments: array, top of stack, value to be pushed
void push(int* stack, int* top, int value) {
  printf ("top is %d\n", *top);
    
  if(*top > 7) {
    printf("Stack overflow has happened. Aborting. Cannot push. Make space.");
    exit(1);
  }
  
  stack[*top + 1] = value;
  (*top)++;
  // The last two statement could be combined like stack[(*top)++] = value;
}

// argumnets: array, top of stack
// return value: popped element
int pop(int* stack, int* top) {
  printf ("top is %d\n", *top);

  if(*top < 0) {
    printf("Stack underflow has happened. Bailing out.");
    exit(2);
  }

  return stack[(*top)--];
}

// arguments: array, top of stack
// return value: peeked element
int peek(const int*stack, const int* top) {
  return stack[*top];
}

int main() {
  int stack[MAX];
  int top = -1;

  push(stack, &top, 1);
  push(stack, &top, 2);
  push(stack, &top, 3);
  push(stack, &top, 4);
  push(stack, &top, 5);
  push(stack, &top, 6);
  push(stack, &top, 7);
  push(stack, &top, 8);
  //push(stack, &top, 9);
  printf("Popped value is %d\n", pop(stack, &top));
  printf("Popped value is %d\n", pop(stack, &top));
  printf("Popped value is %d\n", pop(stack, &top));
  printf("Popped value is %d\n", pop(stack, &top));
  printf("Popped value is %d\n\n", pop(stack, &top));

  printf("Peeked value at top is %d\n\n", peek(stack, &top));

  printf("Popped value is %d\n", pop(stack, &top));
  printf("Popped value is %d\n", pop(stack, &top));
  printf("Popped value is %d\n", pop(stack, &top));
  printf("Popped value is %d\n", pop(stack, &top));

  return 0;
}
