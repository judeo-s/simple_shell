#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * word_count - a function that counts the number of words in a string.
 *
 * @string: char *
 * @delim: char *
 * Return: int
 */
int word_count(char *string, char *delim)
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

	word = strtok(str, delim);
	while (word != NULL)
	{
		length++;
		word = strtok(NULL, delim);
	}

	_free(str);
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
	char **token = NULL, *word = NULL, *temp_string = NULL;
	int counter = 0, words, w_len;

	words = word_count(string, delim);
	temp_string = buffer_alloc(_strlen(string) + 1);
	token = (char **)malloc((words + 1) * sizeof(char *));

	if (temp_string)
		_strcpy(temp_string, string);

	word = strtok(temp_string, delim);
	while (counter < words)
	{
		w_len = _strlen(word) + 1;
		token[counter] = (char *)buffer_alloc(sizeof(char) * w_len);
		if (!token[counter])
		{
			free_token(token);
			break;
		}
		clear_buffer(token[counter], w_len);
		_strcpy(token[counter], word);
		counter++;
		word = strtok(NULL, delim);
	}
	token[counter] = NULL;
	_free(temp_string);
	return (token);
}


/**
 * token_len - a function to get the length of a token
 *
 * @token: char **
 * Return: int
 */
int token_len(char **token)
{
	int counter = 0;

	while (token[counter])
	{
		counter++;
	}
	return (counter);
}


/**
 * token_copy - a function that copy's the content of a token to another.
 *
 * @neww: char **
 * @old: char **
 * Return: int
 */
int token_copy(char **neww, char **old)
{
	int len, i = 0, str_len;

	if (!old || !neww)
		return (0);

	len = token_len(old);
	while (i < len)
	{
		str_len = _strlen(old[i]);
		neww[i] = buffer_alloc(str_len + 1);

		if (!neww[i])
		{
			free_token(neww);
			return (0);
		}
		_strcpy(neww[i], old[i]);
		i++;
	}
	return (1);
}


/**
 * free_token - a function that frees allocated memory for tokens
 *
 * @token: char **
 * Return: void
 */
void free_token(char **token)
{
	int i;
	int length = token_len(token);

	for (i = 0; i < length; i++)
	{
		_free(token[i]);
	}

	_free(token);
}
