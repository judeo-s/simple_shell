#include "shell.h"
#include <unistd.h>


/**
 * _perror - a function that is used to write custom messages to stderr
 *
 * @message: char *
 * @command: char *
 * Return: void
 */
void _perror(char *command, char *message)
{
	int index = get_key("_", environ);
	char error[BUFFER_SIZE];
	char *shell_name = get_value(index, environ);

	_strstrip(shell_name, '_');
	_strstrip(shell_name, '=');
	sprintf(error, "%s: %lu: %s: %s\n", shell_name, row, command, message);
	write(2, error, _strlen(error));
	_free(shell_name);
}
