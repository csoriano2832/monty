#include "monty.h"
#define UNSUSED(x) (void)(x)
/**
 * pall - prints all the values on the stack, starting from the top of the stack
 * @stack: a doubly linked list representation of a stack
 * @line_number: line number currently being read from file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	UNSUSED(line_number);

	if (*stack == NULL)
	{
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%i\n", tmp->n);
		tmp = tmp->next;
	}
}
