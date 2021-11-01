/**
 * main - displays the information contained in the ELF sections' headers
 * @argc: arg count
 * @argv: args
 * @env:  enviornment
 * Return: 0 on success, else 1
 */
int main(int argc, char **argv, char **env)
{
	char *args[] = {"/usr/bin/readelf", "-W", "-l", "", NULL};

	(void)argc;

	args[3] = argv[1];

	if (execve("/usr/bin/readelf", args, env) == -1)
	{
		perror("execv");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
