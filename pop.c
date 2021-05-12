#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: a doubly linked list representation of a stack
 * @line_number: line number currently being read from file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == EMPTY)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE)
	}

	top = *stack;
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
	
	free(top);
}
