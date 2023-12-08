#include "shell.h"

int main(void)
{
	char *str;
	char *token;

	str = _strdup("this		is\t morocco\n");
	printf("%s\n", str);
	token = strtok(str, " \t\n");

	while (token)
	{
	printf("%s ", token);
	token = strtok(NULL, " \t\n");
	}
	printf("\n");
	return(0);
}
