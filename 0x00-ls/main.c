#include "hsh.h"

ls_flags_t flags = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

/**
 * main - entry point of program
 * @ac: arg count
 * @av: args
 * Return: status
 */
int main(int ac, char **av)
{
	if (ac == 1)
		return (listDirContents("."));
	return (_ls(ac, av));
}
