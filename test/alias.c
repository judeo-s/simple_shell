#include "shell.h"
#include <sys/wait.h>
#include <unistd.h>


/**
 * _alias - a function that is used to create alias commands
 *
 * @command: char **
 * @env: char **
 * Return: int
 */
int _alias(char **command, char **env)
{
	return (0);
}


/**
 * alias_handler - a function that handles alias processing
 *
 * @command: char **
 * @environ: char **
 * @aliases: char **
 * Return: void
 */
void alias_handler(char **command, char **environ, char **aliases)
{
	_puts("will work on this latter");
}
