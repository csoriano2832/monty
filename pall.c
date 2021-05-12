#include "monty.h"

/**
 * pall - prints all the values on the stack, starting from the top of the stack
 * @stack: a doubly linked list representation of a stack
 * @line_number: line number currently being read from file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	while (tmp != NULL)
	{
		tmp = *stack;
		print("%i\n", tmp->n);
		tmp = tmp->next;
	}
}
