#include "readelf.h"

/**
 * main - displays the info in the ELF program headers of an ELF file
 * @argc: arg count
 * @argv: args
 * @env:  enviornment
 * Return: 0 on success, else 1
 */
int main(int argc, char **argv, char **env)
{
	char *args[] = {"/usr/bin/readelf", "-W", "-s", "", NULL};

	(void)argc;

	args[3] = argv[1];

	if (execve("/usr/bin/readelf", args, env) == -1)
	{
		perror("execv");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
