#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

void process_handler(char **token)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error:");
	}
	else if (pid == 0)
	{
		if (execve(token[0], token, NULL) == -1)
		{
			perror("Error:");
		}
	}
	else
	{
		wait(NULL);
	}
}
