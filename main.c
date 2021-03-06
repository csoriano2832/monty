#include "monty.h"
int main(int argc, char *argv[]);

/**
 * main - main entry point
 * @argc: number of arguments
 * @argv: arguments in a string array
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *file;
	unsigned int n, line_num = 0, i;
	char buff[10000], *content[10000], *token, *opcode;
	stack_t *stack = NULL;

	if (argc != 2)
		errors(1, NULL, 0);
	
	file = fopen(argv[1], "r");

	if (file == NULL)
		errors(2, argv[1], 0);
	
	while (fgets(buff, 10000, file) != NULL)
	{
		token = strtok(buff, "\n");

		while (token != NULL)
		{
			content[line_num] = strdup(token);
			line_num++;
			token = strtok(NULL, "\n");
		}
	}
	content[line_num] = NULL;

	for (i = 0; content[i] != NULL; i++)
	{
		token = strtok(content[i], " \t");
		if (token != NULL)
		{
			opcode = strdup(token);
			if (strcmp(opcode, "push") == 0)
			{
				token = strtok(NULL, " \t");
				n = atoi(token);
				if (n == 0 && strcmp(token, "0") != 0)
					errors(4, NULL, i + 1);
				get_func(opcode)(&stack, n);
			}
			else if (opcode[0] == '#')
			{
				nop(&stack, line_num);
			}
			else
			{
				if (get_func(opcode) == NULL)
				{
					errors(3, opcode, i + 1);
					exit(EXIT_FAILURE);
				}
				get_func(opcode)(&stack, line_num);
			}
			free(opcode);
		}
	}

	for (; line_num > 0; line_num--)
		free(content[line_num]);

	free(content[0]);
	fclose(file);
	free_list(stack);
	stack = NULL;
	return (0);
}
