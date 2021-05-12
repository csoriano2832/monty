#include "monty.h"
/**
 * get_func - get func
 * @s: function to use
 * Return: func to be used
 */
void (*get_func(char *s))(stack_t **, unsigned int)
{
	 instruction_t func[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	 };
	int i = 0;


	while (func[i].opcode != NULL && strcmp((func[i].opcode), s) != 0)
		i++;
	return (func[i].f);
}
