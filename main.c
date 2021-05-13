#include "monty.h"
/**
 *
 *
 *
 */
int main (int argc, char *argv[])
{
	FILE *file;
	ssize_t read_content;
	unsigned int n, line_num = 0, i;
	char buff[10000], *content[10000], *token, *opcode;
	stack_t **stack;

	if (argc != 2)
	{
		errors(1, NULL, 0);
	}
	if ((file = fopen(argv[1], "r")) == NULL)
	{
		errors(2, argv[1], 0);
	}

	while (fgets(buff,10000, file) != NULL)
	{
		token = strtok(buff, "\n");

		while (token != NULL)
		{
			content[line_num] = strdup(token);
			line_num++;
			token = strtok(NULL, buff);
		}
	}

	for (i = 0; content[i] != NULL; i++)
	{

		token = strtok(content[i], " ");
		while (token != NULL)
		{
			opcode = strdup(token);
			if (get_func(opcode) == NULL)
			{
				errors(3, NULL, i + 1);
				exit(EXIT_FAILURE);
			}
			token = strtok(NULL, content[i]);

			n = atoi(token);
			if (strcmp(opcode, "push") == 0)
			{
				get_func(opcode)(stack, n);
				break;
			}
			else
			{
				get_func(opcode)(stack, line_num);
				break;
			}
		break;}
	}
	return(0);
}
