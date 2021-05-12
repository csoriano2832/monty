#include "monty.h"

int errors(int err, char *str)
{
	switch (err) {
		case 1:
			write(2, "USAGE: monty file", 17);
			break;
		case 2:
			fprintf(stderr,"Error: Can't open file %s", str);
			break;

	}
	return(0);
}
