#ifndef SHELL_H
#define SHELL_H

char **tokenizer(char *string, char *delim);
void free_token(char **token, int length);
int word_count(char *string);

void shell(char **env);

void process_handler(char **token, char **env);

void print_env(char *env[]);
int get_envlen(char **env);
int get_key(char *var_name, char **env);
char *get_value(int key, char **env);

char *_realloc(char *buffer, int size);
void _memcpy(char *dest, char *src, unsigned int n);
char *buffer_alloc(int size);

void clear_buffer(char *buffer, int size);
void print_buffer(char *buffer);

int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
void _puts(char *str);

#endif
