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

char *line_reader(void);
int _strcmp(char *s, char *ss);
char *_strdup(const char *string);
int _strlen(char *str);
char *_strcat(char *destination, char *source);
void _strcpy(char *source, char *dest);
int main(void);

#endif /*SHELL_H*/
