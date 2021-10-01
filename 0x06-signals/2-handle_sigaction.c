#include "signals.h"

/**
 * handle_sigaction -
 * Return: 
 */
int handle_sigaction(void)
{
	struct sigaction sa;

	sa.sa_handler = handle_SIGINT;
	return (sigaction(SIGINT, &sa, NULL));
}

/**
 * handle_SIGINT - sigint handler
 * @signum: number we're using to print
 */
void handle_SIGINT(int signum)
{
	printf("Gotcha! [%d]\n", signum);
	fflush(stdout);
}