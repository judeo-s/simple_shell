#include "shell.h"
#include <stdio.h>
#include <unistd.h>


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


/**
 * _strstrip - a function that strips characters from strings.
 *
 * @str: char *
 * @c: char
 * Return: void
 */
void _strstrip(char *str, char c)
{
	int i, j;

	for (i = 0; i < _strlen(str); i++)
	{
		if (str[i] == c)
		{
			for (j = i; j < _strlen(str); j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}


/**
 * _getline -  a function that is used to read input from a line.
 *
 * @lineptr: char **
 * @n: size_t
 * @stream: FILE *
 * Return: ssize_t
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t nread = 0;
	size_t len = 0;
	char *line = NULL;
	char buffer[BUFFER_SIZE * 100];

	if (!lineptr || !n)
		return (-1);

	while ((nread = read(_fileno(stream), buffer, BUFFER_SIZE)) > 0)
	{
		line = buffer_alloc(len + nread + 2);
		if (line == NULL)
		{
			return (-1);
		}
		_memcpy(line, buffer, len + nread + 2);
		len += nread;

		if (buffer[nread - 1] == '\n')
			break;
	}
	if (len == 0)
		return (-1);

	line[len] = '\0';
	*lineptr = line;
	*n = len;
	return (len);
}


/**
 * _isspace - checks if a character is a space
 *
 * @c: int
 * Return: 1 if true, 0 if false
 */
int _isspace(int c)
{
	return (c == ' ');
}


/**
 * is_only_spaces - checks if a string is only composed of spaces
 *
 * @str: char *
 * Return: 1 if true, 0 if false
 */
int is_only_spaces(char *str)
{
	while (*str != '\0')
	{
		if (!_isspace(*str))
			return (0);
		str++;
	}
	return (1);
}
