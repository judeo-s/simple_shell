#include "shell.h"

/**
 * command_handler - a function that handles commands processing
 *
 * @token: char **
 * @env: char **
 * Return: void
 */
void command_handler(char **command, char **environ, char **aliases)
{
	builtin_t command_list[] = {
		{"cd", _cd}, {"env", _env},
		{"setenv", _setenv}, {"unsetenv", _unsetenv}
	};
	int counter = 0, result, success;

	if (!_strcmp("alias", command[0]))
	{
		alias_handler(command, environ, aliases);
		return;
	}

	while (counter < 4)
	{
		result = _strcmp(command_list[counter].command, command[0]);

		if(!result)
		{
			success = command_list[counter].handler(command, environ);
			return;
		}
		counter++;
	}

	path_handler(command, environ);
	process_handler(command, environ);
}
