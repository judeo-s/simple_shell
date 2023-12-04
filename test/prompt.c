#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

char *clean_input(char *string)
{
	char *str = NULL;
	int len;

	len = _strlen(string);
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);

	clear_buffer(str, len);
	_strncpy(str, string, len - 1);
	return (str);
}

void shell()
{
	char *input = NULL;
	size_t n_read;
	size_t len = 0;
	char **token = NULL;
	int words;

	printf("$ ");

	n_read = getline(&input, &len, stdin);
	input = clean_input(input);
	token = tokenizer(input);
	process_handler(token);	
	words = word_count(input);
	free_token(token, words);
	free(input);
}
