#include "monty.h"
/**
 * free_list - frees linked list
 * @head: head node of list
 */
void free_list(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
