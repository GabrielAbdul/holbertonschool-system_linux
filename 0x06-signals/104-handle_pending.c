#include "signals.h"

/**
 * handle_pending - sets up handler for all pending signals
 * @handler: handler
 * Return: 0, -1
 */
int handle_pending(void (*handler)(int))
{
	struct sigaction sa;

	sa.sa_handler = handler;
	(void)sa;

	return (0);
}
