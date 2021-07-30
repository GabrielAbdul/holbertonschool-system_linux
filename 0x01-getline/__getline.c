#include "_getline.h"

/**
 * __getline - description
 * @file: file
 * Return: line
 */
char *__getline(fd_t *file)
{
	int buflen, nullByte = false;
	char *buf = malloc(sizeof(char) * READ_SIZE);

	buflen = getNewline(file);
	if (buflen == 0)
	{
		strcpy(buf, file->buf);
		free(file->buf);
		file->buf = NULL;
		file->bytes = 0;
		file->bufsize = 0;
		if (buf[0] == '\0')
			return (NULL);
		return (buf);
	}
	if (buflen == 0)
		return (NULL);
	_memcpy(buf, file->buf, buflen);
	if (buf[buflen - 1] == '\n')
		nullByte = true;
	buf[buflen - 1] = '\0';
	file->bytes -= buflen;
	if (file->bytes < 0)
		file->bytes = 0;
	_memcpy(file->buf, file->buf + buflen, file->bytes);

	return (buf[0] == '\0' && !nullByte ? NULL : buf);
}

/**
 * getNewline - description
 * @file: file to find newline
 * Return: line length
 */
int getNewline(fd_t *file)
{
	int len;
	ssize_t bytes;

	while ((len = lineLen(file->buf)) == -1)
	{
		file->bufsize = file->bytes + READ_SIZE + 1;
		file->buf = realloc(file->buf, sizeof(char) * file->bufsize);
		if ((bytes = read(file->fd, file->buf + file->bytes, READ_SIZE)) <= 0)
			return (0);
		file->bytes += bytes;
		file->buf[file->bufsize] = '\0';
	}
	return (len);
}

/**
 * _memcpy - custom memcpy
 * @dest: dest string
 * @src: src string
 * @bytes: bytes to cpy
 */
void _memcpy(char *dest, char *src, int bytes)
{
	int i;

	for (i = 0; i < bytes; i++)
		dest[i] = src[i];
	dest[i] = '\0';
}

/**
 * lineLen - finds character in string
 * @line: str
 * Return: int
 */
int lineLen(char *line)
{
	int i = 0;

	if (!line)
		return (-1);

	for (i = 0; line[i]; i++)
		if (line[i] == '\n' && _strlen(line) > 1)
			return (i + 1);
	return (0);
}

/**
 * _strlen - custom strlen
 * @s: string
 * Return: string length
 */
size_t _strlen(char *s)
{
	size_t len = 0;

	if (s)
		while (s[len])
			len++;
	return (len);
}
