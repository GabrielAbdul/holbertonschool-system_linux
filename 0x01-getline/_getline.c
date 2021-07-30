#include "_getline.h"
#include "__getline.c"
/**
 * _getline - reads an entire line from a file descriptor
 * @fd: file descriptor to read from
 * Return: line
 */
char *_getline(const int fd)
{
	fd_t *file = NULL;

	if ((file = getFd(fd)) == NULL)
		return (NULL);

	return (__getline(file));
}

/**
 * getFd - searches for file descriptor or adds new one to list
 * @fd: fd were looking for
 * Return: file
 */
fd_t *getFd(const int fd)
{
	static fd_t *fds;
	fd_t *file = NULL, *prev = NULL;

	if (fd == -1)
	{
		freeFds(fds);
		return (NULL);
	}
	for (file = fds; file; file = file->next)
	{
		if (file->fd == fd)
			break;
		prev = file;
	}
	if (file == NULL)
	{
		file = malloc(sizeof(fd_t));
		if (!file)
			return (NULL);
		file->fd = fd;
		file->buf = NULL;
		file->bytes = 0;
		file->bufsize = 0;
		file->next = NULL;
		if (prev)
			prev->next = file;
		else
			fds = file;
	}
	return (file);
}

/**
 * freeFds - frees list of fds
 * @fds: file descriptors
 */
void freeFds(fd_t *fds)
{
	if (!fds)
		return;

	freeFds(fds->next);
	free(fds->buf);
	free(fds);
}
