#include "signals.h"

/**
 * handle_sigaction -
 * Return: 
 */
int handle_sigaction(void)
{
	struct sigaction sa;
	struct sigaction oa;

	sa.sa_handler = handle_SIGINT;
	oa.sa_handler = signal(SIGINT, SIG_DFL);
	return (sigaction(SIGINT, &sa, &oa));
}

/**
 * handle_SIGINT - sigint handler
 * @signum: number we're using to print
 */
void handle_SIGINT(int signum)
{
	printf("Gotcha! [%d]\n", signum);
}