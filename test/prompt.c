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
	char **input = NULL;
	int n_read;
	size_t len = 0;
	char **command = NULL;
	char **alias = NULL;
	char *entry = NULL;
	int i = 0;

	_puts("$ ");
	n_read = _getline(&entry, &len, stdin);
	if (n_read == -1)
	{
		_free(input);
		free_token(*env);
		_puts("\n");
		exit(0);
	}

	input = tokenizer(entry, "\n");
	_free(entry);
	while (input[i])
	{
		if (!input[i] || !_strlen(input[i]) || is_only_spaces(input[i]))
		{
			i++;
			continue;
		}
		command = tokenizer(input[i], " ");
		if (!_strcmp(command[i], "exit"))
			free_token(input);

		command_handler(command, env, &alias);
		len = 0;
		free_token(command);
		i++;
	}
	free_token(input);
}
