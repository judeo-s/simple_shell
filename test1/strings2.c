#include "shell.h"

/**
 *_strcat - a function to concatinate to strings
 *
 * @dest: char pointer
 * @src: char pointer
 * Return: char pointer
 */
char *_strcat(char *dest, char *src)
{
	int dest_len = _strlen(dest);
	int src_len = _strlen(src);
	int total_len = dest_len + src_len;

	int counter = 0;
	int i;

	for (i = dest_len; i < total_len; i++)
	{
		dest[i] = src[counter];
		counter++;
	}

	return (dest);
}
