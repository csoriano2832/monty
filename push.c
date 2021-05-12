#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: a doubly linked list representation of a stack
 * @line_number: line number currently being read from file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node->n = line_number;
	node->next = NULL;
	
	if (*stack == NULL)
	{
		node->prev = NULL;
	}
	else
	{
		node->prev = *stack;
		node->prev->next = node;
	}
	
	*stack = node;
}