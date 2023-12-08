#include "shell.h"

char **env;

int executer(char **cmd, char **argv)
{
	pid_t child_fork;
	int sts;

	child_fork = fork();
	if (child_fork == 0)
	{
		if (execve(cmd[0], cmd, env) == -1)
		{
			perror(argv[0]);
			freeStrArray(cmd);
			exit(0);
		}
	}
	else
	{
		waitpid(child_fork, &sts, 0);
		freeStrArray(cmd);
	}
	return (WEXITSTATUS(sts));
}
