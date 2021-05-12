#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: a doubly linked list representation of a stack
 * @line_number: line number currently being read from file
 */
void add(stack_t **stack, unsigned int line_number)
{
	unsigned int elements = 0;
	stack_t *tmp = *stack, *top = *stack;

	while (tmp != NULL)
	{
		tmp = tmp->prev;
		elements++;
	}

	if (elements < 2)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	(*stack) = (*stack)->prev;
	(*stack)->next = NULL;
	
	(*stack)->n += top->n;
	
	free(top);
}
