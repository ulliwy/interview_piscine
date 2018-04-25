#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	struct s_queue *qu = queueInit();
	enqueue(qu, "Here");
	enqueue(qu, "comes");
	enqueue(qu, "the");
	enqueue(qu, "day");
	printf("- %s\n", dequeue(qu));

	struct s_node *node = qu->first;
	while (node)
	{
		printf("+ %s\n", node->message);
		node = node->next;
	}

	printf("- %s\n", dequeue(qu));
	printf("- %s\n", dequeue(qu));
	printf("- %s\n", dequeue(qu));
	printf("- %s\n", dequeue(qu));
	printf("isEmpty: %d\n\n", isEmpty(qu));

	while (node)
	{
		printf("+ %s\n", node->message);
		node = node->next;
	}

	printf("peek: %s\n", peek(qu));
	enqueue(qu, "Here");
	enqueue(qu, "comes");
	enqueue(qu, "the");
	enqueue(qu, "day");

	while (node)
	{
		printf("+ %s\n", node->message);
		node = node->next;
	}

	printf("peek: %s\n", peek(qu));
	printf("isEmpty: %d\n", isEmpty(qu));

	return (0);
}



// Function used for the test
// Don't go further :)

