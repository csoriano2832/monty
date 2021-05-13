#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: a doubly linked list representation of a stack
 * @line_number: line number currently being read from file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == EMPTY)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%i\n", (*stack)->n);
}
