#include "monty.h"

/**
 * divide - divides the top two elements of the stack
 * @stack: a doubly linked list representation of a stack
 * @line_number: line number currently being read from file
 */
void divide(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;

	if (top->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n /= top->n;

	free(top);
}
