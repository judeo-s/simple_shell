
#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc __attribute__((unused)), char *argv[])
{
	char *input = NULL;
	size_t n_read;
	size_t len = 0;
	char **token = NULL;

	printf("$ ");

	n_read = getline(&input, &len, stdin);
	token = tokenizer(input);

	if (execve(token[0], token, NULL) == -1)
	{
		perror("Error:");
	}
	free(input);
	return (0);
}
