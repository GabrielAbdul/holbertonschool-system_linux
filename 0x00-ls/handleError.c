#include "hsh.h"

/**
 * handleError - handles errors
 * @node: node
 */
void handleError(dir_list_t *node)
{
	char *buf = malloc(sizeof(char) * 1024);

	if (node->errNum == ENOENT)
	{
		sprintf(buf, "%s: cannot access %s: No such file or directory \n", node->programName, node->dirName);
		fprintf(stderr, "%s", buf);
	}
	else
	{
		node->errNum = CANTOPEN;
		sprintf(buf, "%s: cannot open directory %s: Permission denied\n", node->programName, node->dirName);
		fprintf(stderr, "%s", buf);
	}
	free(buf);
	flags.exit = 2;
}
