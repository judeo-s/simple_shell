#include "shell.h"

/**
 * command_handler - a function that handles commands processing
 *
 * @command: char **
 * @environ: char **
 * @aliases: char **
 * Return: void
 */
void command_handler(char **command, char ***environ, char ***aliases)
{
	char cmd[BUFFER_SIZE];
	builtin_t command_list[] = {
		{"cd", _cd}, {"env", _env},
		{"setenv", _setenv}, {"unsetenv", _unsetenv},
		{"exit", __exit}
	};
	int counter = 0, result;

	clear_buffer(cmd, BUFFER_SIZE);
	_strcpy(cmd, command[0]);
	if (!_strcmp("alias", command[0]))
	{
		alias_handler(command, environ, aliases);
		return;
	}

	while (counter < 5)
	{
		result = _strcmp(command_list[counter].command, command[0]);

		if (!result)
		{
			result = command_list[counter].handler(command, environ);
			return;
		}
		counter++;
	}

	path_handler(command, *environ);
	if (!command[0])
	{
		_perror(cmd, "not found");
		return;
	}
	process_handler(command, environ);
}
