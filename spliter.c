#include "shell.h"

char **line_spliter(char *line)
{
	char *token = NULL;
	char *tmp = NULL;
	char delimiters[] = " \t\n";
	char **command = NULL;
	int counter = 0, i = 0;

	if (!line)
		return (NULL);

	tmp = _strdup(line);
	token = strtok(tmp, delimiters);

	if (token == NULL)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}

	while(token)
	{
		counter++;
		token = strtok(NULL, delimiters);
	}
	free(tmp), tmp = NULL;

	command = malloc(sizeof(char *) * (counter + 1));
	if (!command)
	{
		free(line), line = NULL;
		return (NULL);
	}
	token = strtok(line, delimiters);
	while(token)
	{
		command[i] = _strdup(token);
		token = strtok(NULL, delimiters);
		i++;
	}
	command[i] = NULL;
	free(line), line = NULL;
	return (command);
}
