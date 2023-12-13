#include "shell.h"
#include <stdlib.h>


/**
 * _cd - a function that is used to change the current directory
 *
 * @command: char **
 * @env: char **
 * Return: int
 */
int _cd(char **command __attribute__((unused)),
		char ***env __attribute__((unused)))
{
	return (0);
}


/**
 * _setenv - a function that sets the environment variable.
 *
 * @command: char **
 * @env: char **
 * Return: int
 */
int _setenv(char **command, char ***env)
{
	int index, result, var_len;
	char **temp;

	if (!command[1] || !command[2])
	{
		_perror("Command syntax: setenv VARIABLE VALUE\n");
		return (0);
	}

	index = get_key(command[1], *env);

	if (index == -1)
	{
		result = add_variable(command[1], command[2], env);
		if (result)
			return (1);
		else
			return (0);
	}
	else
	{
		temp = *env;
		var_len = _strlen(command[1]) + _strlen(command[2]) + 2;
		_free(temp[index]);
		temp[index] = buffer_alloc(var_len);
		_strcat(temp[index], command[1]);
		_strcat(temp[index], "=");
		_strcat(temp[index], command[2]);
	}
	return (0);
}


/**
 * _unsetenv - a function that is used to delete a environment variable.
 *
 * @command: char **
 * @env: char **
 * Return: int
 */
int _unsetenv(char **command __attribute__((unused)),
		char ***env __attribute__((unused)))
{
	int result;

	if (!command[1])
	{
		_perror("Command syntax: unsetenv VARIABLE\n");
		return (0);
	}
	result = delete_variable(command[1], env);
	if (result)
		return (1);

	return (0);
}


/**
 * _env - a function that prints the environment variablesx
 *
 * @command: char **
 * @env: char **
 * Return: int
 */
int _env(char **command __attribute__((unused)),
		char ***env)
{
	print_env(*env);
	return (1);
}


/**
 * __exit - a command to exit the program
 *
 * @command: char **
 * @env: char **
 * Return: int
 */
int __exit(char **command, char ***env)
{
	int status = 0;

	if (command[1])
	{
		status = _atoi(command[1]);
	}

	free_token(*env);
	free_token(command);
	exit(status);
}
