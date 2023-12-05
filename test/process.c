#include "shell.h"
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>


/**
 * process_handler - that creates forks a process for any command
 *
 * @token: char **
 * @env: char **
 * Return: void
 */
void process_handler(char **token, char **env)
{
	int key = get_key("PATH", env);
	char *value = get_value(key, env);
	char **dirs = tokenizer(value, ":");

	print_env(dirs);

	if (execve(token[0], token, dirs) == -1)
	{
		perror("Error:");
	}

}
