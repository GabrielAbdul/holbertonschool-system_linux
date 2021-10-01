#include "signals.h"

/**
 * handle_signal - sets a handler for the singal SIGNINT
 * Return: int
 */
int handle_signal(void)
{
	int signum = 2;

	return ((signal(SIGINT, handle_SIGINT) == SIG_ERR) ? EXIT_FAILURE : signum);

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
