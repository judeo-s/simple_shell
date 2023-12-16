#include "shell.h"
#include <dirent.h>
#include <unistd.h>

/**
 * set_DIRVAR - a function that is used to set the value of OLDPWD
 *
 * @env: char ***
 * @var: char *
 * Return: int
 */
int set_DIRVAR(char ***env, char *var)
{
	char **temp = *env;
	char *key = var;
	int index = get_key(key, temp);
	char *value = getcwd(NULL, 0), *variable;

	variable = buffer_alloc(_strlen(key) + _strlen(value) + 2);
	if (!variable)
	{
		_free(value);
		return (0);
	}
	_strcat(variable, key);
	_strcat(variable, "=");
	_strcat(variable, value);
	_free(temp[index]);
	_free(value);
	temp[index] = variable;
	return (1);
}


/**
 * cd_directory - a function that changes the directory of a program.
 *
 * @path: char *
 * @env: char ***
 * Return: int
 */
int cd_directory(char *path, char ***env)
{
	DIR *dir;
	char *old, **old_token;
	int key;

	if (!_strcmp(path, "-"))
	{
		key = get_key("OLDPWD", *env);
		old = get_value(key, *env);
		old_token = tokenizer(old, "=");
		set_DIRVAR(env, "OLDPWD");
		chdir(old_token[1]);
		_puts(old_token[1]);
		_puts("\n");
		set_DIRVAR(env, "PWD");

		_free(old);
		free_token(old_token);
		return (1);
	}

	dir = opendir(path);
	if (dir == NULL)
		return (0);

	set_DIRVAR(env, "OLDPWD");
	chdir(path);
	set_DIRVAR(env, "PWD");
	_free(dir);
	return (1);
}
