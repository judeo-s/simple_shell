#include <unistd.h>


/**
 * _strlen - a function that returns the size of a string
 *
 * @s: Pointer to an char variable
 * Return: int
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}


/**
 * _puts - a function that prints a string
 *
 * @str: Pointer to an char variable
 * Return: void
 */
void _puts(char *str)
{
	int i;

	if (str)
		for (i = 0; str[i] != '\0'; ++i)
			write(1, &str[i], 1);
}


/**
 * _strcpy - a function that copies string from a source to destination
 *
 * @dest: Pointer to a char variable
 * @src:  Pointer to a char variable
 * Return: void
 */
void _strcpy(char *dest, char *src)
{
	int x;
	int len = _strlen(src);

	for (x = 0; x < len; x++)
	{
		dest[x] = src[x];
	}
}


/**
 *_strncpy - a function to copies a strings to n-size of another string
 *
 * @dest: char pointer
 * @src: char pointer
 * @n: int
 * Return: void
 */
void _strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
}


/**
 *_strcmp - a function to copies a strings to n-size of another string
 *
 * @s1: char pointer
 * @s2: char pointer
 * Return: int
 */
int _strcmp(char *s1, char *s2)
{
	int src_len = _strlen(s1);
	int i, result = 0;

	for (i = 0; i < src_len; i++)
	{
		if (s1[i] == s2[i])
		{
			continue;
		}
		else
		{
			result = s1[i] - s2[i];
			break;
		}
	}

	return (result);
}
