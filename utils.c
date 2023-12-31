#include "shell.h"
#include <stdio.h>
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


/**
 * _fileno - a function that returns the file number of a fuke stream.
 *
 * @stream: FILE *
 * Return: int
 */
int _fileno(FILE *stream)
{
	int file_descriptor;

	if (stream == NULL)
		return (-1);

	file_descriptor = -1;
	if (stream == stdin)
		file_descriptor = STDIN_FILENO;

	if (stream == stdout)
		file_descriptor = STDOUT_FILENO;

	if (stream == stderr)
		file_descriptor = STDERR_FILENO;

	return (file_descriptor);
}


/**
 * _atoi - a function that converts converts a string to an integer.
 *
 * @s: char *
 * Return: int
 */
int _atoi(char *s)
{
	unsigned int integer = 0;
	int sign = 1, i = 0;

	do {
		if (s[i] == '-')
			sign *= -1;

		else if (s[i] >= '0' && s[i] <= '9')
			integer = (integer * 10) + (s[i] - '0');

		else if (s[i] > '9' || s[i] < '0')
		{
			return (0);
		}
		i++;
	} while (s[i]);

	return (integer * sign);
}
