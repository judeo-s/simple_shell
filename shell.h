#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>

#define BUFFER_SIZE 1024
#define _free(ptr) __free((void **)&(ptr))

extern unsigned long row;
extern char **input, **environ, **multi_command;
extern int status;

/**
 * struct builtin_command_list - a struct used to create a list of builtins
 *                      and their corresponding functions
 * @command: char *
 * @handler: (int)(*handler)(char **, char **)
 */
typedef struct builtin_command_list
{
	char *command;
	int (*handler)(char **, char ***);
} builtin_t;


char **tokenizer(char *string, char *delim);
void free_token(char **token);
int word_count(char *stringi, char *delim);
int token_len(char **token);
int token_copy(char **neww, char **old);

void shell(char ***env);

void get_absolute(char **path, char *file);
void path_handler(char **command, char **environ);

void signal_handler(int sig);

void process_handler(char **token, char ***env);

void command_handler(char **command, char ***environ, char ***alias);

void alias_handler(char **command, char ***environ, char ***aliases);
int _alias(char **command, char ***env);

int _cd(char **command, char ***env);
int _setenv(char **command, char ***env);
int _unsetenv(char **command, char ***env);
int _env(char **command, char ***env);
int __exit(char **command, char ***env);

void print_env(char *env[]);
int get_key(char *var_name, char **env);
char *get_value(int key, char **env);
int add_variable(char *key, char *value, char ***env);
int delete_variable(char *key, char ***env);
void __free(void **ptr);
void *_realloc(void *buffer, int size);
void _memcpy(char *dest, char *src, unsigned int n);
void *buffer_alloc(int size);

void clear_buffer(char *buffer, int size);
void print_buffer(char *buffer);
int _fileno(FILE *stream);
int _atoi(char *s);

int _strlen(char *str);
void _strcpy(char *dest, char *src);
void _strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
void _puts(char *str);

char *_strcat(char *dest, char *src);
void _strstrip(char *str, char c);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int _isspace(int c);
int is_only_spaces(char *str);

int _istab(int c);
int is_only_tabs(char *str);
char *_strchr(char *s, char c);

void _perror(char *command, char *message);
#endif
