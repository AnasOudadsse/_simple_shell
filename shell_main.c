#include "shell.h"

/**
 * main - simple shell main function
 * @counter: count of arguments
 * @args: arguments
 * Return: 0 in success
*/

char **environ;

int main(int counter, char **args, char *envp[])
{
	char *line = NULL;
	char **command = NULL;
	int status = 0;
	int index = 0;
	(void) counter;

	if (envp == NULL)
    {
        fprintf(stderr, "Error: envp is NULL, main.c\n");
        return EXIT_FAILURE;
    }
	environ = envp;

	while(10)
	{
		line = line_reader();
		if (line == NULL)/* reach end of file ; Ctrl + D*/
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n",1);
			return (status);
		}
		index++;
		command = line_spliter(line);
		if (!command)
			continue;
		status = executer(command, args, index);
	}
}
