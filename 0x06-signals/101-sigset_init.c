#include "signals.h"

/**
 * sigset_init - initializes a sigset
 * @set: pointer to sig set to init
 * @signals: 0-terminated array of int, each one being a signum
 * Return: 0, or -1
 */
int sigset_init(sigset_t *set, int *signals)
{
	int i;

	/* initializes set to exclude all defined signals */
	sigemptyset(set);

	for (i = 0; sigaddset(set, signals[i]) == 0; i++)
		;

	return (signals[i] == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}
