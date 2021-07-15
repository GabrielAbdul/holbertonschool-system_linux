#include "hsh.h"

#define printDirHeader (!node->errNum && !node->isFile && ((node->next ||\
					   (node->prev && node->next == NULL))))

/**
 * printFilesFirst - prints all the input files before directories
 * @dirs: head node of inputs
 * Return: numDirs
 */
int printFilesFirst(dir_list_t *dirs)
{
	char **files;
	int i = 0, j = 0, flag = 0, directory = 0, file = 0, numDirs = 0;
	dir_list_t *node = NULL;

	files = malloc(sizeof(char *) * 100);
	for (node = dirs; node; node = node->next)
	{
		if (node->isFile == 1)
		{
			files[i] = _strdup(node->dirName);
			i++;
			file = true;
		}
		if (node->isFile == 0)
		{
			directory = true;
			numDirs++;
		}
	}
	for (j = 0; j < i; j++)
	{
		if (files[j])
		{
			printf("%s", files[j]);
			flag = 1;
			if (j != i - 1)
				putchar(' ');
		}
	}
	if (flag == 1)
		putchar('\n');
	if (directory == true && file == true)
		flags.dirAndFilePrint = true;
	free(files);
	return (numDirs);
}

/**
 * printList - prints directory contents
 * @dirs: first directory in list
 */
void printList(dir_list_t *dirs)
{
	int numDirs = 0, i = 0;
	file_list_t *file = NULL;
	dir_list_t *node = NULL;

	numDirs = printFilesFirst(dirs);
	if (flags.dirAndFilePrint)
		putchar('\n');
	for (node = dirs; node; node = node->next)
	{
		if (printDirHeader)
			printf("%s:\n", node->dirName);
		for (file = node->fileList; file; file = file->next, i++)
		{
			if (flags.hidden)
				printf("%s", file->fileName);
			else if (!flags.hidden && file->fileName[0] != '.')
				printf("%s", file->fileName);
			else if (flags.almostAll)
				if (!file->fileName[0] == '.' && !_strlen(file->fileName) <= 2)
					printf("%s", file->fileName);
			if (node->numFiles > 1 && numDirs >= 0)
					putchar(' ');
			node->numFiles--;
		}
		if (!node->isFile)
			if ((node->next || !node->next) && !flags.newline)
				putchar('\n');
		if (--numDirs > 0)
			putchar('\n');
	}
}

/**
 * buildPermissionString - builds permission string for long print
 * @st_mode: file mode used for bitmaskign
 * Return: string
 */
char *buildPermissionString(mode_t st_mode)
{
	char *permString = malloc(sizeof(char) * 11);

	permString[0] = (S_ISREG(st_mode)) ? '-' : 'd';
	permString[1] = (S_IRUSR & st_mode) ? 'r' : '-';
	permString[2] = (S_IWUSR & st_mode) ? 'w' : '-';
	permString[3] = (S_IXUSR & st_mode) ? 'x' : '-';
	permString[4] = (S_IRGRP & st_mode) ? 'r' : '-';
	permString[5] = (S_IWGRP & st_mode) ? 'w' : '-';
	permString[6] = (S_IXGRP & st_mode) ? 'x' : '-';
	permString[7] = (S_IROTH & st_mode) ? 'r' : '-';
	permString[8] = (S_IWOTH & st_mode) ? 'w' : '-';
	permString[9] = (S_IXOTH & st_mode) ? 'x' : '-';
	permString[10] = '\0';

	return (permString);
}
