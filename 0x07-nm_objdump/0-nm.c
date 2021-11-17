#include "nm.h"

/**
 * main - displays the information contained in the ELF sections' headers
 * @argc: arg count
 * @argv: args
 * @env:  enviornment
 * Return: 0 on success, else 1
 */
int main(int argc, char **argv, char **env)
{
	char *args[] = {"./hnm", "-p", "", NULL};

	(void)argc;

	args[2] = argv[1];

	if (execve("/usr/bin/nm", args, env) == -1)
	{
		perror("Error: ");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
