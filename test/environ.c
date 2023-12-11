#include "shell.h"
#include <stdlib.h>
#include <stdio.h>
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
 * get_key - a function that is used to get the index of a particular variable
 *
 * @var_name: char *
 * @env: char **
 * Return: int
 */
int get_key(char *var_name, char **env)
{
	int len = token_len(env);
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


/**
 * add_variable - a function that appends data to environment variables
 *
 * @key: char *
 * @value: char *
 * @env: char **
 * Return: int
 */
int add_variable(char *key, char *value, char **env)
{
	int len = token_len(env), var_len, result;
	char **temp, **temp2;

	temp = buffer_alloc(sizeof(char *) * (len + 2));
	if (!temp)
		return (0);

	result = token_copy(temp, env);
	if (result)
	{
		var_len = _strlen(key) + _strlen(value) + 2;
		temp[len] = buffer_alloc(var_len);
		sprintf(temp[len], "%s=%s", key, value);
		temp[len + 1] = NULL;
		env = malloc(sizeof(char *) * (len + 2));
		token_copy(env, temp);
		free_token(temp);
		return (1);
	}
	return (0);
}
