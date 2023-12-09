#include "shell.h"
#include <unistd.h>

/**
 * clear_buffer - a fuction that clears existing data in allocated buffers.
 *
 * @buffer: char *
 * @size: int
 * Return: void
 */
void clear_buffer(char *buffer, int size)
{
	int i;

	for (i = 0; i < size; ++i)
	{
		buffer[i] = '\0';
	}
}



/**
 * print_buffer - a function that is used to print to the screen in chuncks.
 *
 * @buffer: char *
 * Return: void
 */
void print_buffer(char *buffer)
{
	int len = _strlen(buffer);
	int written = 0, to_write, result;

	while (written < len)
	{
		to_write = len - written;
		if (to_write > 1024)
		{
			to_write = 1024;
		}
		result = write(1, buffer + written, to_write);
		if (result == -1)
		{
			break;
		}
		written += result;
	}
}
