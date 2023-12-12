#include "shell.h"


/**
 * getLine - read a line from standard input
 * @linepointer: pointer to the buffer where the line will be stored
 * @n: pointer to the size of the buffer
 * @stream: file stream (not used in this case, always set to stdin)
 *
 * Return: the number of characters read (including the newline character),
 * or -1 on failure
 */
ssize_t getLine(char **linepointer, size_t *n, FILE *stream)
{
	static char buffer[BUFFER_SIZE];
	static size_t buffer_index = 0;
	ssize_t bytes_read = 0;
	ssize_t total_bytes = 0;

	if (*linepointer == NULL || *n == 0)
	{
		// Initialize or reallocate the buffer if necessary
		*n = BUFFER_SIZE;
		*linepointer = (char *)malloc(*n);
		if (*linepointer == NULL)
			return -1;
	}
	while (1)
	{
		// Check if the buffer is empty, and if so, refil
		if ( buffer_index == 0 )
		{
			bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			if (bytes_read <= 0)
				break; // End of file or error
		}

	// Copy characters from the buffer to the lineptr
	while (buffer_index < bytes_read)
	{
		if (buffer[buffer_index] == '\n')
		{
			// End of line, include the newline character
			(*linepointer)[total_bytes++] = buffer[buffer_index++];
			(*linepointer)[total_bytes] = '\0'; // Null-terminate the line
			return total_bytes;
		}
		else
		{
			// Copy character to lineptr and move indices
			(*linepointer)[total_bytes++] = buffer[buffer_index++];
		}
		// Check if the buffer is full, and if so, resize linepointer
		if (total_bytes >= *n - 1)
		{
			*n *= 2;
			*linepointer = (char *)realloc(*linepointer, *n);
			if (*linepointer == NULL)
				return -1;
		}
	}
	// Reset buffer_index since we finished reading the buffer
	buffer_index = 0;
	}
	// If we reach here, we either encountered an error or reached EOF
	if (total_bytes > 0)
		return total_bytes;
	else
		return -1; // Error or EOF without reading any characters
}

