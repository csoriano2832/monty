#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: a doubly linked list representation of a stack
 * @line_number: line number currently being read from file
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *temp;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = line_number;
	new->next = NULL;

	if (!*stack)
	{
		*stack = new;
	}
	else
	{
		temp = *stack;
		new->next = temp;
		temp->prev = new;
		*stack = new;
	}
}
