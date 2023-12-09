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
 * sigintHandler - blocks ctrl-C and prints a new prompt
 * @sig_num: the signal number
 *
 * Return: void
 */
void sigintHandler(int sig_num)
{
	ssize_t written;
	char prompt[] = "$ ";
	
	(void)sig_num;  // To suppress the unused parameter warning

	// Write the prompt to stdout
	written = write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
	if (written == -1)
	{
		perror("write");
		_exit(EXIT_FAILURE);
	}
}

/**
 * handle_eof - handles the end-of-file condition (Ctrl-D)
 * @n_read: ssize_t
 * @input: char *
 *
 * Return: int (1 if EOF is encountered, 0 otherwise)
 */
int eof_handler(ssize_t n_read, char *input)
{
	if (n_read == -1)
	{
		if (feof(stdin))
		{
			// Handle end-of-file (Ctrl-D) condition
			_free(input);
			if (write(STDOUT_FILENO, "\n", 1) == -1)
			{
				perror("write");
				_exit(EXIT_FAILURE);
			}
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			_exit(EXIT_FAILURE);
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
	if (signal(SIGINT, sigintHandler) == SIG_ERR)
	{
		perror("signal");
		exit(EXIT_FAILURE);
	}

	char *input = NULL;
	size_t n_read;
	size_t len = 0;
	char **command = NULL;
	char **alias = NULL;

	char prompt[] = "$ ";
	
	// Write the prompt to stdout
	if (write(STDOUT_FILENO, prompt, sizeof(prompt) - 1) == -1)
	{
		perror("write");
		exit(EXIT_FAILURE);
	}
	n_read = getline(&input, &len, stdin);
	
	if (eof_handler(n_read, input))
		return;
	//if (!n_read)
	//	exit (0);
	input = clean_input(input);
	command = tokenizer(input, " ");
	command_handler(command, env, alias);

	free_token(command);
	_free(input);
}
