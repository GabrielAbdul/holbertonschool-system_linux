#include "signals.h"

/**
 * handle_SIGINT - sigint handler
 * @signum: int
 */
void handle_SIGINT(int signum)
{
        signum = 2;
        printf("Gotcha! [%d]\n", signum);
        fflush(stdout);
}

/**
 * handle_signal - function that set a handler for the signal SIGINT
 * Return: 0 or -1
 */
int handle_signal(void)
{
        if (signal(SIGINT, handle_SIGINT) != 0)
                return (-1);
        return (0);
}

/**
 * main - sets SIGINT handler, exits after signal is received and handled
 * Return: 0 or -1
 */
int main(void)
{
        sigset_t myset;

        /* initialize empty signal mask */
        sigemptyset(&myset);

        if (handle_signal() == -1)
                return (-1);

        /* suspend with empty mask, (any signal can wake up program) */
        sigsuspend(&myset);
        printf("Signal received\n");

        return (0);
}