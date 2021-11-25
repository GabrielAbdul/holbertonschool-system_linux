#include "syscalls.h"

/**
 * main - executes and traces a given command
 * @av: array vector containing a command and its args
 * @ac: arg count
 * Return: int
 */
int main(int ac, char **av, char **envp)
{
    int status = 0, count = 0;
    pid_t pid;
    struct user_regs_struct regs;

    if  (ac <= 1)
    {
        fprintf(stderr, "USAGE: %s command [args...]\n", av[0]);
        return (EXIT_FAILURE);
    }

    setbuf(stdout, NULL);
    pid = fork();
    if (pid == 0)
    {
        printf("%d\n", EXECVE_SYS_NUM);
        ptrace(PTRACE_TRACEME, pid, NULL, NULL);
        execve(av[1], av + 1, envp);
    }
    else
    {
        status = 1;
        while (!WIFEXITED(status))
        {
            count++;
            ptrace(PT_SYSCALL, pid, NULL, NULL);
            wait(&status);
            ptrace(PT_GETREGS, pid, NULL, &regs);
            if (count % 2 == 0)
                printf("%lu\n", (size_t)regs.orig_rax);
            fflush(stdout);
        }
    }
    return (0);
}