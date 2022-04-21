#include "sockets.h"

/**
 * print_error_and_exit - self explanatory
 * @str: program to print error for
 * Return: 0
 */
int print_error_and_exit(char *str)
{
	printf("%s: %s", str, strerror(errno));
	return (EXIT_FAILURE);
}

/**
 * accept_socket - accept an entereing connection, prints the IP address
 *                 of the connected client
 * @socket: socket to accept connection
 * Return: 0 on success, -1 on failure
 */
int accept_socket(int socket)
{
	int new_socket;
	struct sockaddr_in address;
	socklen_t address_len;

	address_len = sizeof(address);
	new_socket = accept(socket,
				(struct sockaddr *)&address, (socklen_t *)&address_len);

	if (new_socket == -1)
		print_error_and_exit("accept");

	printf("Client connected: %s\n", inet_ntoa(address.sin_addr));
	return (EXIT_SUCCESS);


}
/**
 * bind_socket - assigns a name to a socket
 * @socket: socket to assign address (name)
 * Return: 0 on success, -1 on failure
 */
int bind_socket(int socket)
{
	int bin;
	struct sockaddr_in addr;

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(PORT);
	bin = bind(socket, (struct sockaddr *)&addr, sizeof(addr));

	return (bin);
}

/**
 * main - opens an IPv4/TCP socket, and listens to
 *        traffic on port 12345 (Any address), waits for signal
 * Return: 0 on succes, -1 on failure
 */
int main(void)
{
	int socket_fd;

	socket_fd = socket(AF_INET, SOCK_STREAM, 0);

	if (socket_fd == -1)
		print_error_and_exit("socket");

	if (bind_socket(socket_fd) == -1)
		print_error_and_exit("bind");

	if (listen(socket_fd, 1) == -1)
		print_error_and_exit("listen");

	accept_socket(socket_fd);

	printf("Server listening on port %d\n", PORT);
	pause();
	return (EXIT_SUCCESS);
}
