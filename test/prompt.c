#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>


/**
 * clean_input - a function that cleans input from terminal
 *
 * @string: char *
 * Return: char *
 */
char *clean_input(char *string)
{
	char *str = NULL;
	int len;

	len = _strlen(string);
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);

	clear_buffer(str, len);
	_strncpy(str, string, len - 1);
	return (str);
}


/**
 * shell - a function that begins the terminal prompt
 *
 * @env: char **
 * Return: void
 */
void shell(char **env)
{
	char *input = NULL;
	size_t n_read;
	size_t len = 0;
	char **command = NULL;
	char **alias = NULL;

	_puts("$ ");
	n_read = getline(&input, &len, stdin);

	if (!n_read)
		exit (0);
	input = clean_input(input);
	command = tokenizer(input, " ");
	command_handler(command, env, alias);

	free_token(command);
	_free(input);
}
