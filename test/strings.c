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
 * _strcpy - a function that copies string from a source to destination
 *
 * @dest: Pointer to a char variable
 * @src:  Pointer to a char variable
 * Return: *char
 */
char *_strcpy(char *dest, char *src)
{
	char *p;
	char *x = dest;

	if (dest == NULL || src == NULL)
		return (NULL);

	for (p = src; *p; p++)
	{
		*x = *p;
		x++;
	}
	return (dest);
}


/**
 *_strncpy - a function to copies a strings to n-size of another string
 *
 * @dest: char pointer
 * @src: char pointer
 * @n: int
 * Return: char pointer
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}
