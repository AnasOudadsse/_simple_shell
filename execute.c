#include "shell.h"

int executer(char **cmd, char **argv, int index)
{
	pid_t child_fork;
	int sts;
	char *full_command;

	full_command = _getpath(cmd[0]);
	if (!full_command)
	{
		printerror(argv[0], cmd[0], index);
		freeStrArray(cmd);
		return(127);
	}

	printf("Executing: %s\n", full_command);/*debug*/	

	child_fork = fork();
	if (child_fork == 0)
	{
		if (execve(full_command, cmd, env) == -1)
		{
		    perror("execve");  /* Print error message*/
			free(full_command), full_command = NULL;
			freeStrArray(cmd);
		}
	}
	else
	{
		waitpid(child_fork, &sts, 0);
		freeStrArray(cmd);
		free(full_command), full_command = NULL;
	}
	return (WEXITSTATUS(sts));
}
