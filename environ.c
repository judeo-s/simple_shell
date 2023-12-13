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
int add_variable(char *key, char *value, char ***env)
{
	int len = token_len(*env), var_len, result;
	static char **temp;

	temp = buffer_alloc(sizeof(char *) * (len + 2));
	if (!temp)
		return (0);

	result = token_copy(temp, *env);
	if (result)
	{
		var_len = _strlen(key) + _strlen(value) + 2;
		temp[len] = buffer_alloc(var_len);
		_strcat(temp[len], key);
		_strcat(temp[len], "=");
		_strcat(temp[len], value);
		temp[len + 1] = NULL;
		free_token(*env);
		*env = temp;
		return (1);
	}
	return (0);
}


/**
 * delete_variable - a function that deletes an environmet variable
 *
 * @key: char *
 * @env: char ***
 * Return: int
 */
int delete_variable(char *key, char ***env)
{
	int i, size, index;
	char **array = *env;

	index = get_key(key, *env);
	if (index == -1)
	{
		_perror(key);
		_perror(" variable does not exist.\n");
		return (0);
	}

	size = token_len(*env);
	_free(array[index]);
	for (i = index; i < size; i++)
	{
		array[i] = array[i + 1];
	}
	array[size - 1] = NULL;
	return (1);
}
