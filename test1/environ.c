#include "shell.h"
#include <unistd.h>

/**
 * print_env - a function that prints the environment variables
 *
 * @env: char **
 * Return: void
 */
void print_env(char **env)
{
	int i = 0;

	while (env[i])
	{
		print_buffer(env[i]);
		_puts("\n");
		i++;
	}
}


/**
 * get_envlen - a function that gets the total number of environment variables
 *
 * @env: char **
 * Return: int
 */
int get_envlen(char **env)
{
	int length = 0;

	while (env[length])
	{
		length++;
	}
	return (length);
}


/**
 * get_key - a function that is used to get the index of a particular variable
 *
 * @var_name: char *
 * @env: char **
 * Return: int
 */
int get_key(char *var_name, char **env)
{
	int len = get_envlen(env);
	int index = 0, result;

	while (index < len)
	{
		result = _strcmp(var_name, env[index]);

		if (!result)
			return (index);

		index++;
	}
	return (-1);
}


/**
 * get_value - a function that gets the value of a particular env variable
 *
 * @key: int
 * @env: char **
 * Return: char *
 */
char *get_value(int key, char **env)
{
	int len = _strlen(env[key]) + 1;
	char *value = NULL;

	value = buffer_alloc(len);

	if (value)
		_strcpy(value, env[key]);
	return (value);
}
