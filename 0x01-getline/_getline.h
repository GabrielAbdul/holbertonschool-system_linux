#ifndef _GETLINE_H
#define _GETLINE_H

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define true 1
#define false 0
#define READ_SIZE 1024

/**
 * struct fd_s - struct that defines a fd node
 * @buf: buffer to print
 * @fd: fd of file
 * @bytes: index of bytes we've read
 * @bufsize: bufsize
 * @next: next fd node
 */
typedef struct fd_s
{
	char *buf;
	int fd;
	int bytes;
	int bufsize;
	struct fd_s *next;
} fd_t;

size_t _strlen(char *s);
char *_getline(const int fd);
int lineLen(char *haystack);
void _memcpy(char *dest, char *src, int bytes);
char *__getline(fd_t *file);
void freeFds(fd_t *fds);
fd_t *getFd(const int fd);
int getNewline(fd_t *file);
#endif /* GETLINE_H */
