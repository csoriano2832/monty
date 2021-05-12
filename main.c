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
	char content[1000];

	if (argc != 2)
	{
		errors(1, NULL);
		exit(EXIT_FAILURE);
	}

	if((file = fopen(argv[1], "r")) == NULL)
	{
		errors(2, argv[1]);
		exit(EXIT_FAILURE);
	}

	while (!(fscanf(file, "  %s", content)

