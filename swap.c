#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: a doubly linked list representation of a stack
 * @line_number: line number currently being read from file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	unsigned int elements = 0;
	int data = 0;

	while (tmp != NULL)
	{
		tmp = tmp->next;
		elements++;
	}

	if (elements < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short", line_number);
		exit(EXIT_FAILURE);
	}

	data = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = data;
}
