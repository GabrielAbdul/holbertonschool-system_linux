#include "hsh.h"

/**
 * _ls - prints formatted directory contents
 * @ac: arg count
 * @av: args
 * Return: status
 */
int _ls(int ac, char **av)
{
	dir_list_t *node = NULL;

	if (findFlags(ac, av) == 2)
		return (flags.error);
	buildDirList(ac, av, &node);
	sortList(&node);
	printList(node);
	freeDirList(node);
	return (flags.exit);
}
