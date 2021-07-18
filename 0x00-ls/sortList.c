#include "hsh.h"

/**
 * sortList - sorts list based on input flags
 * @node: reference to list
 */
void sortList(dir_list_t **node)
{
	if (flags.reverse)
		reverseList(node);
}

/**
 * reverseList - reverses doubly linked list of directories
 * @head: head of list
 */
void reverseList(dir_list_t **head)
{
	dir_list_t *node = *head, *tmp = NULL;

	while (node != NULL)
	{
		tmp = node->prev;
		node->prev = node->next;
		node->next = tmp;
		node = node->prev;
	}
	if (tmp != NULL)
		*head = tmp->prev;
}
