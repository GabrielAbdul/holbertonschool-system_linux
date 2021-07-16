#include "hsh.h"

/**
 * printFilesFirst - prints all the input files before directories
 * @dirs: head node of inputs
 * Return: numDirs
 */
int *printFilesFirst(dir_list_t *dirs)
{
	char **files;
	int i = 0, j = 0, flag = 0, directory = 0, file = 0, numDirs = 0;
	int *both = malloc(sizeof(int) * 2);
	dir_list_t *node = NULL;

	files = malloc(sizeof(char *) * 100);
	for (node = dirs; node; node = node->next)
	{
		if (node->isFile == 1 && !node->errNum)
			files[i] = _strdup(node->dirName), i++, file = true;
		if (node->isFile == 0)
		{
			directory = true;
			numDirs++;
		}
	}
	both[0] = numDirs;
	both[1] = i;
	for (j = 0; j < i; j++)
	{
		if (files[j])
		{
			printf("%s", files[j]);
			free(files[j]);
			flag = 1;
			if (j != i - 1)
			{
				if (flags.newline)
					putchar('\n');
				else
					putchar(' ');
			}
		}
	}
	if (flag == 1)
		putchar('\n');
	if (directory == true && file == true)
		flags.dirAndFilePrint = true;
	free(files);
	return (both);
}

/**
 * printList - prints directory contents
 * @dirs: first directory in list
 */
void printList(dir_list_t *dirs)
{
	int *numDirsnumFiles, i = 0, numDirs = 0;
	file_list_t *file = NULL;
	dir_list_t *node = NULL;

	numDirsnumFiles = printFilesFirst(dirs), numDirs = numDirsnumFiles[0];
	if (flags.dirAndFilePrint)
		putchar('\n');
	for (node = dirs; node; node = node->next)
	{
		if (node->errNum == ENOENT || node->errNum == CANTOPEN)
			continue;
		if (printDirHeader)
			printf("%s:\n", node->dirName);
		for (file = node->fileList; file; file = file->next)
			if (flags.almostAll)
				(!canPrint(file->fileName)) ? node->numFiles-- : node->numFiles;
		for (file = node->fileList; file; file = file->next, i++)
		{
			if (flags.hidden)
				(flags.longPrint) ? printLong(file), printf("%s", file->fileName), file->printed = 1 : printf("%s", file->fileName), file->printed = 1;
			else if (!flags.hidden && file->fileName[0] != '.' && !flags.almostAll)
				(flags.longPrint) ? printLong(file), printf("%s", file->fileName), file->printed = 1 : printf("%s", file->fileName), file->printed = 1;
			if (flags.almostAll)
				if (canPrint(file->fileName))
					(flags.longPrint) ? printLong(file), printf("%s", file->fileName), file->printed = 1 : printf("%s", file->fileName), file->printed = 1;
			(file->printed) ? node->numFiles-- : node->numFiles;
			if (node->numFiles > 0 && !flags.newline && file->printed && !flags.longPrint)
				putchar(' ');
			if ((flags.newline && file->printed == 1) || (flags.longPrint && file->printed == 1))
				putchar('\n');
		}
		if (!node->isFile)
			if ((node->next || !node->next) && !flags.newline && !flags.longPrint)
				putchar('\n');
		if (!node->isFile && --numDirs > 0)
			putchar('\n');
	}
	free(numDirsnumFiles);
}
/**
 * canPrint - determines if we can print for -A flag
 * @file: file name
 * Return: int
 */
int canPrint(char *file)
{
	if (file[0] == '.')
	{
		if (file[1] == '\0')
			return (0);
		if (file[1] == '.' && file[2] == '\0')
			return (0);
	}
	return (1);
}
