#include "shell.h"
#include <sys/stat.h>
#include <unistd.h>

/**
 * get_absolute - gets the absolute path
 *
 * @path: char **
 * @file: char *
 * Return: void
 */
void get_absolute(char **path, char *file)
{
	int size, i = 0;
	char *temp = NULL;

	while (path[i])
	{
		size = _strlen(path[i]) + _strlen(file) + 2;
		temp = buffer_alloc(size);
		_strcat(temp, path[i]);
		_strcat(temp, "/");
		_strcat(temp, file);
		_free(path[i]);
		path[i] = temp;
		i++;
	}
}


/**
 * path_handler - a function that finds the absolute path for the command
 *
 * @command: char **
 * @environ: char **
 * Return: void
 */
void path_handler(char **command, char **environ)
{
	int key = get_key("PATH", environ);
	char *value = get_value(key, environ);
	char **dirs = tokenizer(value, "=");
	char *PATH = dirs[1];
	char **path = tokenizer(PATH, ":");
	unsigned int i = 0;
	struct stat st;

	if (stat(command[0], &st) != 0)
	{
		get_absolute(path, command[0]);
		_free(command[0]);
		while (path[i])
		{
			if (stat(path[i], &st) == 0)
			{
				command[0] = buffer_alloc(_strlen(path[i]) + 1);
				_strcpy(command[0], path[i]);
				break;
			}
			else
				i++;
		}
	}
	_free(value);
	free_token(dirs);
	free_token(path);
}
