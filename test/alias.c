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
int _alias(char **command __attribute__((unused)),
		char ***env __attribute__((unused)))
{
	return (0);
}


/**
 * alias_handler - a function that handles alias processing
 *
 * @command: char **
 * @environ: char **
 * @__attribute__((unused): unused
 * Return: void
 */
void alias_handler(char **command __attribute__((unused)),
		char ***environ __attribute__((unused)),
		char ***aliases __attribute__((unused)))
{
	_puts("I will work on this later");
}
