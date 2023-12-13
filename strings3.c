#include "shell.h"

/**
 * _istab - checks if a character is a tab
 *
 * @c: int
 * Return: 1 if true, 0 if false
 */
int _istab(int c)
{
	return (c == '\t');
}


/**
 * is_only_tabs - checks if a string is only composed of tab spaces
 *
 * @str: char *
 * Return: 1 if true, 0 if false
 */
int is_only_tabs(char *str)
{
	while (*str != '\0')
	{
		if (!_istab(*str))
			return (0);
		str++;
	}
	return (1);
}


/**
 *_strchr - a function to copy content of a certain string to
 *          another string specific.
 *
 * @s: char *
 * @c: char
 * Return: char *
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (c == '\0')
		return (s);

	return (NULL);
}
