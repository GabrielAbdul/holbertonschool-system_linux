#include "signals.h"

/**
 * main - sends SIGINT signal to a process given its PID
 * @ac: arg count
 * @av: arg array
 * Return: EXIT SUCCESS, or EXIT FAILUIRE
 */
int main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Usage: ./7-signal_send_0 <pid>\n");
		exit(EXIT_FAILURE);
	}

	return (kill(atoi(av[1]), SIGINT) == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}
