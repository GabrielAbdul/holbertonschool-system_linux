#include "multithreading.h"

/**
 * tprintf - use printf to print formatted string
 * Return: 0
 */
int tprintf(char const *format, ...)
{
	printf("[%lu] %s", pthread_self(), format);
	return (EXIT_SUCCESS);
}