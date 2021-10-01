#include "signals.h"

void sig_handler(int signum, siginfo_t *siginfo, void *ucontext);

/**
 * all_in_one - handler for every signal
 */
void all_in_one(void)
{
	int signum;
	struct sigaction sa;

	/* use sa_sigaction because we define SA_SIGINFO flags */
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	/* for each signal */
	for (signum = 0; signum <= SIGRTMAX; signum++)
		/* change signal action to custom action defined is sa struct */
		sigaction(signum, &sa, NULL);
}

/**
 * sig_handler - prints signal info
 * @signum: signal that caused invocation of the handler
 * @siginfo: structure containing further information about the signal
 * @ucontext: contains info saved on the user-space stack by the kernel
 */
void sig_handler(int signum, siginfo_t *siginfo, void *ucontext)
{
	(void)signum;
	(void)ucontext;
	psiginfo(siginfo, "Caught");
}
