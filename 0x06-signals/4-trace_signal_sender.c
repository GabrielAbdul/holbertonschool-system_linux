#include "signals.h"

/**
 * handle_SIGQUIT - SIGQUIT handler, prints the sender's PID
 * @signum: signal number that invoked the handler
 * @siginfo: siginfo_t struct, which contains info about the signal
 * @ucontext: pointer to ucontext structure
 */
void handle_SIGQUIT(int signum, siginfo_t *siginfo, void *ucontext)
{
		pid_t pid = siginfo->si_pid;

		(void)signum;
		(void)ucontext;
		printf("SIGQUIT sent by %d\n", pid);
}
/**
 * trace_signal_sender - defines a SIGQUIT handler
 * Return: 0, -1
 */
int trace_signal_sender(void)
{
		struct sigaction sa;

		/* define our handler */
		sa.sa_sigaction = handle_SIGQUIT;
		/* set our flags */
		sa.sa_flags = SA_SIGINFO;

		return (sigaction(SIGQUIT, &sa, NULL));
}
