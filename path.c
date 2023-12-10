#include "shell.h"

char * _getpath(char *cmd)
{
	char *path, *full_cmd, *direction;
	struct stat st;
	int i;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (_strdup(cmd));
			return (NULL);
		}
	}

	path = _getenv("PATH");
	printf("path.c :PATH: %s\n", path);
	if (!path)
	{
    	fprintf(stderr, "Error: PATH not found in environment\n");
    	return NULL;
	}
	direction = strtok(path, ":");
	while(direction)
	{
		full_cmd = malloc(_strlen(direction) + _strlen(cmd) + 2);
		if (full_cmd)
		{
			_strcpy(full_cmd, direction);
			_strcat(full_cmd, "/");
			_strcat(full_cmd, cmd);

			printf("Trying path: %s\n", full_cmd);/*debug*/

			if (stat(full_cmd, &st) == 0)
			{
				free(path);
				return (full_cmd);
			}

			free(full_cmd), full_cmd = NULL;
			direction = strtok(	NULL, ":");

		}
	}
	free(path);
	return (NULL);
}
