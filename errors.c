#include "monty.h"
/**
 * errors - prints the corresponding error
 * @err: the error
 * @str: string to be printed
 * @line_num: line number currently being read
 *
 * Return: 0 on success
 */
int errors(int err, char *str, int line_num)
{
	switch (err)
	{
		case 1:
			write(2, "USAGE: monty file\n", 17);
			exit(EXIT_FAILURE);
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", str);
			exit(EXIT_FAILURE);
			break;
		case 3:
			fprintf(stderr, "L%i: unknown instruction %s\n", line_num, str);
			exit(EXIT_FAILURE);
			break;
		case 4:
			fprintf(stderr, "L%i: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
			break;


	}
	return (0);
}
