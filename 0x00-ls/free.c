#include "hsh.h"

/**
 * freeDirList - frees all dir nodes of everythign
 * @head: head of dirs
 */
void freeDirList(dir_list_t *head)
{
	dir_list_t *node = NULL;
	file_list_t *file = NULL;

	while (head)
	{
		node = head;
		head = head->next;

		if (node->fileList)
		{
			while (node->fileList)
			{
				file = node->fileList;
				node->fileList = node->fileList->next;
				free(file->fileName);
				free(file);
			}
		}
		free(node);
	}
}
