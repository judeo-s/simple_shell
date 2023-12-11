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
		char **env __attribute__((unused)))
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
int _setenv(char **command, char **env)
{
	int index, result;

	if (!command || !command[0] || !command[1])
		return (0);

	_strstrip(command[1], '"');
	_strstrip(command[2], '"');

	index = get_key(command[1], env);

	if (index == -1)
	{
		result = add_variable(command[1], command[2], env);
		if (result)
			return (1);
		else
			return (0);
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
		char **env __attribute__((unused)))
{
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
		char **env __attribute__((unused)))
{
	print_env(env);
	return (1);
}


/**
 * __exit - a command to exit the program
 *
 * @command: char **
 * @env: char **
 * Return: int
 */
int __exit(char **command, char **env)
{
	free_token(env);
	free_token(command);
	exit(0);
}
