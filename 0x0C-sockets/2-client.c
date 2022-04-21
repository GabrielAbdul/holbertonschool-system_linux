#include "sockets.h"

/**
 * main - entry point
 * @ac: arg count
 * @av: arg vectpr
 * Return: int
 */
int main(int ac, char **av)
{
	int socket_fd;
	char *host;
	unsigned short port;
	struct sockaddr_in addr;

	if (ac != 3)
	{
		printf("Usage: %s <host> <port>", av[0]);
		return (EXIT_FAILURE);
	}
	host = strcmp(av[1], "localhost") ==  ? "127.0.0.1" : "localhost";
	port = atoi(av[2]);

	socket_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_fd == -1)
	{
		printf("socket_fd: %s", strerror(errno));
		return (EXIT_FAILURE);
	}
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr(host);
	addr.sin_port = htons(port);
	if (connect(socket_fd, (struct sockaddr *)&addr, sizeof(addr)) == -1)
	{
		printf("connect: %s\n", strerror(errno));
		return (EXIT_FAILURE);
	}
	printf("Connected to %s:%d\n", av[1], port);
	return (EXIT_SUCCESS);
}
