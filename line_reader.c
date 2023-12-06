#include "shell.h"


char *line_reader(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t charnbr;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	charnbr = getline(&line, &len, stdin);
	if (charnbr == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
