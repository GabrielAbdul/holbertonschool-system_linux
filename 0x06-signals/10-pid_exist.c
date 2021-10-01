#include <signal.h>
#include <stdlib.h>

/**
 * pid_exist - tests if a process exists, given its PID
 * @pid: process id
 * kill return 0 on success, we want to return 1, so + 1
 * Return:  int
 */
int pid_exist(pid_t pid)
{
	return (kill(pid, 0) + 1);
}
