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
void process_handler(char **token, char ***env)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error:");
	}
	else if (pid == 0)
	{
		if (execve(token[0], token, *env) == -1)
		{
			perror("Error:");
		}
	}
	else
	{
		wait(NULL);
	};
}
