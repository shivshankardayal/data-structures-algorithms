stack:	stack.c stack.h
	gcc -Wall -Werror -pedantic -std=c11 stack.c -o stack

queue:	queue.c queue.h
	gcc -Wall -Werror -pedantic -std=c11 queue.c -o queue

stack_ll: stack_ll.c stack_ll.h
	gcc -Wall -Werror -pedantic -std=c11 stack_ll.c -o stack_ll

queue_ll: queue_ll.c queue_ll.h
	gcc -Wall -Werror -pedantic -std=c11 queue_ll.c -o queue_ll
