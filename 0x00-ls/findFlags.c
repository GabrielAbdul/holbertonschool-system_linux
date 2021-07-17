#include "hsh.h"
/**
 * findFlags - finds ls flags
 * @ac: arg count
 * @av: args
 * Return: a status code
 */
int findFlags(int ac, char **av)
{
	int i, j;

	for (i = 0; i < ac; i++)
	{
		if ((av[i][0]) == '-')
			for (j = 1; av[i][j]; j++)
				switch (av[i][j])
				{
				case ('1'):
					flags.newline = true;
					break;
				case ('a'):
					flags.hidden = true;
					break;
				case ('A'):
					flags.almostAll = true;
					break;
				case ('l'):
					flags.longPrint = true;
					break;
				case ('r'):
					flags.reverse = true;
					break;
				case ('S'):
					flags.size = true;
					break;
				case ('R'):
					flags.recursive = true;
					break;
				default:
					flags.error = 2;
					fprintf(stderr, "hls: invalid option == '%c'\n", av[i][j]);
					fprintf(stderr, "Try 'hls --help' for more information.\n");
					break;
				}
	}
	return (flags.error);
}
