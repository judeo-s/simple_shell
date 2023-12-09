#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#define _free(ptr) __free((void **)&(ptr))

typedef struct builtin_command_list
{
	char *command;
	int (*handler)(char **, char **);
} builtin_t;


char **tokenizer(char *string, char *delim);
void free_token(char **token);
int word_count(char *stringi, char *delim);
int token_len(char **token);

void shell(char **env);

void get_absolute(char **path, char *file);
void path_handler(char **command, char **environ);

void process_handler(char **token, char **env);

void command_handler(char **command, char **environ, char **alias);

void alias_handler(char **command, char **environ, char **aliases);

int _alias(char **command, char **env);
int _cd(char **command, char **env);
int _setenv(char **command, char **env);
int _unsetenv(char **command, char **env);
int _env(char **command, char **env);

void print_env(char *env[]);
int get_envlen(char **env);
int get_key(char *var_name, char **env);
char *get_value(int key, char **env);

void __free(void **ptr);
char *_realloc(char *buffer, int size);
void _memcpy(char *dest, char *src, unsigned int n);
char *buffer_alloc(int size);

void clear_buffer(char *buffer, int size);
void print_buffer(char *buffer);

int _strlen(char *str);
void _strcpy(char *dest, char *src);
void _strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
void _puts(char *str);

char *_strcat(char *dest, char *src);
int handle_eof(ssize_t n_read, char *input)

#endif
