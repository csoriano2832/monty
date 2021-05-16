#include "monty.h"

/**
 * sub - subtracts the top two elements of the stack
 * @stack: a doubly linked list representation of a stack
 * @line_number: line number currently being read from file
 */
void sub(stack_t **stack, unsigned int line_number)
{
	unsigned int elements = 0;
	stack_t *tmp = *stack, *top = *stack;

	while (tmp != NULL)
	{
		tmp = tmp->next;
		elements++;
	}

	if (elements < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;

	(*stack)->n -= top->n;

	free(top);
}
