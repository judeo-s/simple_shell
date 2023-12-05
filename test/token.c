#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * word_count - a function that counts the number of words in a string.
 *
 * @string: char *
 * Return: int
 */
int word_count(char *string)
{
	int len, length = 0;
	char *str = NULL, *word = NULL;

	if (string == NULL)
		return (0);

	len = _strlen(string) + 1;
	str = (char *)malloc(sizeof(char) * len);

	if (!str)
		return (0);

	clear_buffer(str, len);
	_strcpy(str, string);

	if (!str)
		return (0);

	word = strtok(str, " ");
	while (word != NULL)
	{
		length++;
		word = strtok(NULL, " ");
	}
	return (length);
}



/**
 * tokenizer - a function that creates a token of strings.
 *
 * @string: char *
 * @delim: char *
 * Return: char **
 */
char **tokenizer(char *string, char *delim)
{
	char **token = NULL, *word = NULL;
	int counter = 0, words, w_len;

	words = word_count(string);
	token = malloc((words + 1) * sizeof(char *));

	word = strtok(string, delim);
	while (word != NULL)
	{
		w_len = _strlen(word) + 1;
		token[counter] = (char *)malloc(sizeof(char) * w_len);
		if (!token[counter])
		{
			free_token(token, counter + 1);
			break;
		}
		clear_buffer(token[counter], w_len);
		_strcpy(token[counter], word);
		counter++;
		word = strtok(NULL, delim);
	}
	token[counter] = NULL;
	return (token);
}


/**
 * free_token - a function that frees allocated memory for tokens
 *
 * @token: char **
 * @length: int
 * Return: void
 */
void free_token(char **token, int length)
{
	int i;

	for (i = 0; i < length; i++)
	{
		free(token[i]);
	}

	free(token);
}
