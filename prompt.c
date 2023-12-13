#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


/**
 * remove_comments - a function that removes comments from inputs
 *
 * @command: char *
 * Return: void
 */
void remove_comments(char **command)
{
	char *comment_start, *prev_char;

	comment_start = _strchr(*command, '#');
	if (comment_start != NULL)
	{
		prev_char = comment_start - 1;
		if (_isspace(*prev_char))
			*comment_start = '\0';
	}
}


/**
 * input_handler - a function that processes the user's input.
 *
 * @command: char ***
 * @input: char *
 * @env: char ***
 * @alias: char **
 * Return: int
 */
int input_handler(char ***command, char *input, char ***env, char **alias)
{
	_strstrip(input, 39);
	_strstrip(input, '"');
	if (!isatty(STDIN_FILENO))
		row++;
	*command = tokenizer(input, " ");
	if (*command)
		command_handler(*command, env, &alias);
	else
		return (0);
	return (1);
}


/**
 * shell - a function that begins the terminal prompt
 *
 * @env: char **
 * Return: void
 */
void shell(char ***env)
{
	char **command = NULL, **alias = NULL, *entry = NULL;
	int n_read, i = 0, result;
	size_t len = 0;

	if (isatty(STDIN_FILENO))
		_puts("$ ");
	n_read = _getline(&entry, &len, stdin);
	if (n_read == -1)
	{
		free_token(*env);
		if (isatty(STDIN_FILENO))
			_puts("\n");
		exit(0);
	}
	input = tokenizer(entry, "\n");
	_free(entry);
	if (isatty(STDIN_FILENO))
		row++;
	while (input[i])
	{
		if (!input[i] || !_strlen(input[i]) || is_only_spaces(input[i])
				|| is_only_tabs(input[i]) || input[i][0] == '#')
		{
			i++;
			continue;
		}
		remove_comments(&input[i]);
		result = input_handler(&command, input[i], env, alias);
		if (!result)
		{
			free_token(command);
			break;
		}
		len = 0;
		i++;
		free_token(command);
	}
	free_token(input);
}
