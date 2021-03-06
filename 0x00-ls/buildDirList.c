#include "hsh.h"

/**
 * buildFileList - fills file_list_t nodes with file info
 * @dirNode: directory node, can contain multiple file nodes
 */
void buildFileList(dir_list_t *dirNode)
{
	DIR *dir = NULL;
	struct stat info;
	struct dirent *read = NULL;
	char *buf = malloc(sizeof(char) * 1024);
	file_list_t *node = NULL, *prev = NULL;

	dir = opendir(dirNode->dirName);
	if (!dir)
	{
		if ((lstat(dirNode->dirName, &info) == -1))
			dirNode->errNum = ENOENT, handleError(dirNode);
		else if (!(info.st_mode & S_IROTH))
			handleError(dirNode);
		dirNode->isFile = 1, free(buf);
	}
	if (dir)
	{
		while ((read = readdir(dir)))
		{
			node = malloc(sizeof(file_list_t));
			node->next = NULL, node->printed = 0, node->last = 0;
			if (flags.longPrint)
			{
				node->info = malloc(sizeof(struct stat));
				sprintf(buf, "%s/%s", dirNode->dirName, read->d_name);
				lstat(buf, node->info);
			}
			node->fileName = _strdup(read->d_name), node->prev = prev;
			if (prev)
				node->prev->next = node;
			prev = node;
			if (dirNode->fileList == NULL)
				dirNode->fileList = node;
			dirNode->numFiles++;
		}
		node->last = true;
		free(buf), closedir(dir);
	}
}
/**
* buildDirList - builds linked list of directory nodes
* @ac: arg count
* @av: args
* @node: head node
* Return: int
*/
void buildDirList(int ac, char **av, dir_list_t **node)
{
	int i;
	dir_list_t *dir = NULL, *prev = NULL;

	if (ac == 2 && av[1][0] == '-')
	{
		*node = dirListNodeCreate(av[0], ".");
		return;
	}
	for (i = 1; i < ac; i++)
	{
		if (av[i][0] != '-')
		{
			dir = dirListNodeCreate(av[0], av[i]);
			if (!*node)
				*node = dir;
			dir->prev = prev;
			if (prev)
				dir->prev->next = dir;
			prev = dir;
		}
	}
}

/**
 * dirListNodeCreate - creats dir_list_t node
 * @dir: dirName
 * @program: name of program
 * Return: node created
 */
dir_list_t *dirListNodeCreate(char *program, char *dir)
{
	dir_list_t *node = NULL;

	node = malloc(sizeof(dir_list_t));

	if (!node)
		return (NULL);
	node->dirName = dir;
	node->programName = program;
	node->errNum = 0;
	node->isFile = 0;
	node->numFiles = 0;
	node->fileList = NULL;
	node->prev = NULL;
	node->next = NULL;
	buildFileList(node);
	return (node);

}

/**
 * listDirContents - prints directory contents
 * @dirName: name of directory
 * Return: status
 */
int listDirContents(char *dirName)
{
	struct stat buf;
	struct dirent *read = NULL;
	DIR *dir = opendir(dirName);
	int numFiles = 0, i = 0;

	while ((read = readdir(dir)) != NULL)
	{
		if (read->d_name[0] != '.')
			numFiles++;
	}
	closedir(dir);
	dir = opendir(dirName);
	while ((read = readdir(dir)))
	{
		lstat(read->d_name, &buf);
		if (read->d_name[0] != '.')
		{
			printf("%s", read->d_name);
			i++;
			if (i == numFiles)
				putchar('\n');
			else
				putchar(' ');
		}
	}
	closedir(dir);
	return (0);
}
