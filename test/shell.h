#ifndef SHELL_H
#define SHELL_H

char **tokenizer(char *string);
void free_token(char **token, int length);
void print_token(char **);
void clear_buffer(char *buffer, int size);
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);

#endif
