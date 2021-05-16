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
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"mul", mul},
		{"div", divide},
		{"mod", mod},
		{NULL, NULL}
	 };
	int i = 0;


	while (func[i].opcode != NULL && strcmp((func[i].opcode), s) != 0)
		i++;
	return (func[i].f);
}
