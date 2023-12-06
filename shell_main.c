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
	int status;
	(void) counter;

	while(10)
	{
		line = line_reader();

		command = line_spliter(line);

		status = executer(command, args);
	}

}
