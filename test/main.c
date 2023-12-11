#include "shell.h"
#include <unistd.h>
#include <signal.h>

/**
 * main - a function that begins the entire progrom
 *
 * @argc: int
 * @argv: char **
 * @env: char **
 * Return: int
 */
int main(int argc __attribute__((unused)),
		char *argv[] __attribute__((unused)), char *env[])
{
	char **environ = NULL;
	int env_len;

	signal(SIGINT, signal_handler);
	env_len = token_len(env);
	environ = buffer_alloc(sizeof(char *) * (env_len + 1));
	token_copy(environ, env);

	while (1)
	{
		shell(environ);
	}
	return (0);
}
