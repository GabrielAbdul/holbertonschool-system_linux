#include "signals.h"

/**
 *  current_handler_sigaction - retrieves SIGINT handler or NULL
 * Return: handler or NULL on failure
 */
void (*current_handler_sigaction(void))(int)
{
	struct sigaction sa;

	return (sigaction(SIGINT, &sa, NULL) == -1 ? NULL : sa.sa_handler);
}
