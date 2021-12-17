#include "multithreading.h"

/**
 * thread_entry - serves as the entry point to a new thread
 * @arg: address of a string that must be printed and followed by a new line
 * Return: NULL
 */
void *thread_entry(void *arg)
{
	printf("%s\n", (char *) arg);
	pthread_exit(NULL);
}
