#include "shell.h"
#include <sys/wait.h>
#include <unistd.h>

/**
 * alias_handler - a function that handles alias processing
 *
 * @token: char **
 * @env: char **
 * Return: void
 */
void alias_handler(char **command, char **environ, char **aliases)
{
	_puts("will work on this latter");
}
