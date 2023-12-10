#include "shell.h"


char *_getenv(char *var)
{
    char *cpy, *key, *value, *env, **env_var;
    int i;

	if (environ == NULL)
    {
        fprintf(stderr, "Error: env is NULL\n");
        return NULL;
    }

    printf("Checking contents of env in _getenv:\n");
    for (env_var = environ; *env_var != NULL; env_var++)
        printf("%s\n", *env_var);


    printf("Getting environment variable: %s\n", var); /*debug*/

    for (i = 0; environ[i]; i++)
    {	
		printf("i am environ :%s\n", environ[i]);
        cpy = _strdup(environ[i]);
        key = strtok(cpy, "=");
		printf("the cpy is :%s\n", cpy);
		printf("the key is :%s\n", key);
        if (_strcmp(key, var) == 0)
        {
            value = strtok(NULL, "\n");
            env = _strdup(value);
            free(cpy);
			printf("i am env :%s\n", env);
            return (env);
        }
        free(cpy), cpy = NULL;
    }
    return (NULL);
}
