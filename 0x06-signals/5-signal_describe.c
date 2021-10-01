#include "signals.h"

/**
 * main - prints signal descriptions
 * @ac: arg count
 * @av: argument array
 * Return: 0
 */
int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Usage: ./5-signal_describe <signum>\n");
		exit(EXIT_FAILURE);
	}

	printf("%s: %s\n", av[1], strsignal(atoi(av[1])));
	return (0);
}
