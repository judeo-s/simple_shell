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
void shell(char **env)
{
	char *input = NULL;
	int n_read;
	size_t len = 0;
	char **command = NULL;
	char **alias = NULL;

	_puts("$ ");
	n_read = _getline(&input, &len, stdin);

	if (n_read == -1)
	{
		_free(input);
		free_token(env);
		_puts("\n");
		exit(0);
	}
	_strstrip(input, '\n');

	if (!input || !_strlen(input) || is_only_spaces(input))
	{
		_free(input);
		return;
	}

	command = tokenizer(input, " ");
	_free(input);
	command_handler(command, env, alias);

	len = 0;
	free_token(command);
	_free(input);
}
