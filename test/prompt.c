#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


/**
 * shell - a function that begins the terminal prompt
 *
 * @env: char **
 * Return: void
 */
void shell(char ***env)
{
	char **input = NULL, **command = NULL, **alias = NULL, *entry = NULL;
	int n_read, i = 0;
	size_t len = 0;

	if (isatty(STDIN_FILENO))
		_puts("$ ");
	n_read = _getline(&entry, &len, stdin);
	if (n_read == -1)
	{
		_free(input);
		free_token(*env);
		if (isatty(STDIN_FILENO))
			_puts("\n");
		exit(0);
	}
	input = tokenizer(entry, "\n");
	_free(entry);
	row++;
	while (input[i])
	{
		if (!input[i] || !_strlen(input[i]) || is_only_spaces(input[i])
				|| is_only_tabs(input[i]))
		{
			i++;
			continue;
		}
		_strstrip(input[i], 39);
		_strstrip(input[i], '"');
		if (!isatty(STDIN_FILENO))
			row++;
		command = tokenizer(input[i], " ");
		if (!_strcmp(command[0], "exit"))
			free_token(input);
		command_handler(command, env, &alias);
		free_token(command);
		len = 0;
		i++;
	}
	free_token(input);
}
