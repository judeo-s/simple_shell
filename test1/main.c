#include "shell.h"
#include <unistd.h>


/**
 * main - a function that begins the entire progrom
 *
 * @argc: int
 * @argv: char **
 * @env: char **
 * Return: int
 */
int main(int argc __attribute__((unused)), char *argv[], char *env[])
{
	while (1)
	{
		shell(env);
	}
	return (0);
}
