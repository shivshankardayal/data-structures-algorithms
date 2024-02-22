#include "min_heap.h"

int main()
{
	Heap *head = NULL;
	head = create_heap(head);
	push(head, 10);
	printf("Pushing element : 10\n");
	push(head, 3);
	printf("Pushing element : 3\n");
	push(head, 2);
	printf("Pushing element : 2\n");
	push(head, 8);
	printf("Pushing element : 8\n");
	printf("Top element = %d \n", top(head));
	push(head, 1);
	printf("Pushing element : 1\n");
	push(head, 7);
	printf("Pushing element : 7\n");
	push(head, 18);
	printf("Pushing element : 18\n");
	push(head, 13);
	printf("Pushing element : 13\n");
	printf("Top element = %d \n", top(head));
	pop(head);
	printf("Popping an element.\n");
	printf("Top element = %d \n", top(head));
	pop(head);
	printf("Popping an element.\n");
	printf("Top element = %d \n", top(head));
	return 0;
}
