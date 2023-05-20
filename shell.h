#ifndef SHELL_H
#define SHELL_H
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;

int _strlen(char *str);
char *_strcpy(char *desk, char *src);
size_t _strncmp(char *str1, char *str2, size_t k);
char *_strcat(char *desk, char *src);
int _strcmp(char *str1, char *str2);
size_t _strpn(const char *str1, const char *str2);
char *_strchr(const char *str, int chars);
size_t _strsnp(const char *str1, const char *str2);
char *_strtok(char *str, const char *delim);
char *_get_command(void);
char **_token(char *lineptre);
void exit_command(char **arg, char *lineptre, int _exits);
void _getenv(char **env);
int _fork(char **arg, char **name, char **env, char *lineptre, int id, int count);
char **separatePath(char *path);


int _paths(char **arg, char **env);
char *_path(char **env);


#endif
