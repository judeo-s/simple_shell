#include "shell.h"
#include <stdlib.h>
#include <unistd.h>


/**
 * _cd - a function that is used to change the current directory
 *
 * @command: char **
 * @env: char **
 * Return: int
 */
int _cd(char **command, char ***env)
{
	int result, key;
	char *value, **home_token;

	if (command[0] && !command[1])
	{
		key = get_key("HOME", *env);
		value = get_value(key, *env);
		home_token = tokenizer(value, "=");
		set_DIRVAR(env, "OLDPWD");
		chdir(home_token[1]);
		set_DIRVAR(env, "PWD");

		_free(value);
		free_token(home_token);
		result = 1;
	}
	if (command[0] && command[1])
		result = cd_directory(command[1], env);

	if (!result)
		_perror(command[0], "directory does not exist");

	return (result);
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
		_perror(command[0], "command syntax is setenv VARIABLE VALUE");
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
		_perror(command[0], "command syntax is unsetenv VARIABLE");
		return (0);
	}
	result = delete_variable(command[1], env);
	if (result)
		return (1);

	_perror(command[0], "variable does not exist");
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
	if (command[1])
	{
		status = _atoi(command[1]);
		if (status < 0)
		{
			_perror(command[0], " illegal number!! Use positive integer");
			return (0);
		}
	}
	free_token(multi_command);
	free_token(input);
	free_token(*env);
	free_token(command);
	exit(status);
}
