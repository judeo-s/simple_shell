#include "shell.h"


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
 * handle_eof - a function to handle the end-of-file condition.
 *
 * @n_read: ssize_t
 * @input: char *
 * Return: int (1 if EOF is encountered, 0 otherwise)
 */

int handle_eof(ssize_t n_read, char *input)
{
	if (n_read == -1)
	{
		if (feof(stdin))
		{
		// Handle end-of-file (Ctrl+D) condition
			free(input);
			printf("\n"); // Optionally print a newline before exiting
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}
	return 0;
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

	if (handle_eof(n_read, input))
		return;
	//if (!n_read)
	//	exit (0);
	input = clean_input(input);
	command = tokenizer(input, " ");
	command_handler(command, env, alias);

	free_token(command);
	_free(input);
}
