#include "shell.h"


char *_getenv(char *var)
{
    char *cpy, *key, *value, *environment, **env_var;
    int i;

	if (env == NULL)
    {
        fprintf(stderr, "Error: env is NULL\n");
        return NULL;
    }

    printf("Checking contents of env in _getenv:\n");
    for (env_var = env; *env_var != NULL; env_var++)
        printf("%s\n", *env_var);


    printf("Getting environment variable: %s\n", var); /*debug*/

    for (i = 0; env[i]; i++)
    {
        cpy = _strdup(env[i]);
        key = strtok(cpy, "=");
        if (_strcmp(key, var) == 0)
        {
            value = strtok(NULL, "\n");
            environment = _strdup(value);
            free(cpy);
            return (environment);
        }
        free(cpy), cpy = NULL;
    }
    return (NULL);
}
