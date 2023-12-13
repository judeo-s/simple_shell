#include "shell.h"
#include <unistd.h>


/**
 * _perror - a function that is used to write custom messages to stderr
 *
 * @message: char *
 * Return: void
 */
void _perror(char *message)
{
	write(2, message, _strlen(message));
}
