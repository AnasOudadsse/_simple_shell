#include "shell.h"

/**
 * main - simple shell main function
 * @counter: count of arguments
 * @args: arguments
 * Return: 0 in success
*/

int main(int counter, char **args)
{
	char *line = NULL;
	char **command = NULL;
	int status = 0;
	(void) counter;

	while(10)
	{
		line = line_reader();
		if (line == NULL)/* reach end of file ; Ctrl + D*/
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n",1);
			return (status);
		}
		command = line_spliter(line);
		if (!command)
			continue;

		status = executer(command, args);
	}

}
