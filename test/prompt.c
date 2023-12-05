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
	char **token = NULL;
	int words;

	_puts("$ ");
	n_read = getline(&input, &len, stdin);
	input = clean_input(input);
	token = tokenizer(input, " ");
	process_handler(token, env);
	words = word_count(input);
	free_token(token, words);
	free(input);
}
