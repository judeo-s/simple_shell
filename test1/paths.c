#include "shell.h"
#include <sys/stat.h>

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
	
	while (path[i])
	{
		size = _strlen(path[i]) + _strlen(file) + 2;
		path[i] = _realloc(path[i], size);
		_strcat(path[i], "/");
		_strcat(path[i], file);
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
	unsigned int i = 0, size;
	struct stat st;

	get_absolute(path, command[0]);

	while (path[i])
	{
		size = _strlen(path[i]);
		if (stat(path[i], &st) == 0)
		{
			command[0] = _realloc(path[i], size);
			break;
		}
		else
			i++;
	}
	//_free(value);
	//free_token(dirs);
	//free_token(path);
}
