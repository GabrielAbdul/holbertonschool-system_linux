#ifndef SIGNALS_H
#define SIGNALS_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

/* TASK PROTOTYPES */
int handle_signal(void);
void (*current_handler_signal(void))(int);
int handle_sigaction(void);
void (*current_handler_sigaction(void))(int);
int trace_signal_sender(void);
int pid_exist(pid_t pid);
void all_in_one(void);
int sigset_init(sigset_t *set, int *signals);
int signals_block(int *signals);
int signals_unblock(int *signals);
int handle_pending(void (*handler)(int));

/* CUSTOM FUNCTION PROTOTYPES */
void handle_SIGINT(int signum);
#endif /* SIGNALS_H */
