#ifndef SHELL_H
#define SHELL_H

extern int BUFFER_SIZE;

void shell();

char **tokenizer(char *string);
void free_token(char **token, int length);
int word_count(char *string);

void process_handler(char **token);

void clear_buffer(char *buffer, int size);
char *_realloc(char *buffer, int size);
void _memcpy(char *dest, char *src, unsigned int n);
char *buffer_alloc(int size);

int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);

#endif
