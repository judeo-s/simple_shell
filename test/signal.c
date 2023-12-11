#include "shell.h"


/**
 * signal_handler - a function that is used to handle Ctrl+C
 *
 * @sig: int
 * Return: void
 */
void signal_handler(int sig __attribute__((unused)))
{
	_puts("\n");
	_puts("$ ");
}
