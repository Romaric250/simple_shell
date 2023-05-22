#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;

size_t _strpn(const char *str1, const char *str2);
size_t _strncmp(char *s1, char *s2, size_t x);
int _strlen(char *str);
char *_strcat(char *desk, char *src);
int _strlen(char *str);
size_t _strspn(const char *str1, const char *str2);

int _strcmp(char *s1, char *s2);

char *_strcpy(char *desk, char *src);

char *_get_path(char **env);
int _values_path(char **arg, char **env);
char *_getline_command(void);
void _getenv(char **env);
char **_get_token(char *lineptr);
void _exit_command(char **args, char *lineptr, int _exit);
int _fork_fun(char **arg, char **av, char **env,
char *lineptr, int np, int c);
char *_strtok(char *str, const char *delim);


#endif /* SHELL_H */
