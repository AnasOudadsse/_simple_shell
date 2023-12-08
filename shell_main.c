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
	int status = 0, i;
	(void) counter;
	(void) args;

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

		for (i = 0; command[i]; i++)
			printf("%s\n", command[i]);

		/*status = executer(command, args);*/
	}

}
