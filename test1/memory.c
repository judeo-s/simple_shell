#include <stdlib.h>
#include "shell.h"

/**
 *_memcpy - a function to copy content of a certain string to
 *          another string specific.
 *
 * @dest: char *
 * @src: char *
 * @n: unsigned int
 * Return: char *
 */
void _memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
}


/**
 * buffer_alloc - a fuction that allocates heap memory
 * @size: int
 * Return: char *
 */
char *buffer_alloc(int size)
{
	static char *buffer;

	buffer = malloc(size);
	if (!buffer)
		return (NULL);

	clear_buffer(buffer, size);
	return (buffer);
}


/**
 * _realloc - a function that reallocates more memory for parsed buffer.
 *
 * @buffer: char *
 * @size: int
 * Return: char *
 */
char *_realloc(char *buffer, int size)
{
	static char *new_buffer;

	new_buffer = buffer_alloc(size);
	if (new_buffer)
	{
		_memcpy(new_buffer, buffer, _strlen(buffer));
	}
	else
		return (NULL);

	return (new_buffer);
}


/**
 * __free - a function that frees up some memory space
 *
 * @ptr: void **
 * Return: void
 */
void __free(void **ptr)
{
	if (*ptr != NULL && ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
