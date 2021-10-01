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

/**
 * signals_unblock - blocks a given set of signals
 * from being delivered to the current process
 * @signals: set of signals
 * Return: 0, or -1
 */
int signals_unblock(int *signals)
{
	sigset_t sigset;

	/* initilize sigset with signals */
	if (sigset_init(&sigset, signals) == 0)
		/* specify to unblock the signals in sigset */
		return (sigprocmask(SIG_UNBLOCK, &sigset, NULL));

	return (EXIT_FAILURE);
}
