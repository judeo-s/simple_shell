
#include "shell.h"
#include <unistd.h>

int main(int argc __attribute__((unused)), char *argv[])
{
	while (1)
	{
		shell();
	}
	return (0);
}
