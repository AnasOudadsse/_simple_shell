#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;
int executer(char **cmd, char **argv, int index);
char *line_reader(void);
char **line_spliter(char *line);
int _strcmp(char *s, char *ss);
char *_strdup(const char *string);
int _strlen(char *str);
char *_strcat(char *destination, char *source);
void freeStrArray(char **array);
char *_strcpy(char *destination, char *source);
char * _getenv(char *var);
char * _getpath(char *cmd);
void printerror(char *name, char *cmd, int idx);
char *_itoa(int n);
void reverse_str(char *str, int len);
#endif /*SHELL_H*/
