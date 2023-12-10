#include "shell.h"

/**
 * _strdup - Duplicates a string in a newly allocated memory space.
 * @string: The input string to be duplicated.
 *
 * Return: Pointer to the duplicated string, or NULL on failure or if input is NULL.
 */
char *_strdup(const char *string)
{
	char *ptr;
	int i = 0;
	int length = 0;

	if (string == NULL)
		return (NULL);
	while (*string != '\0')
	{
		length++;
		string++;
	}
	string = string - length;
	ptr = malloc(sizeof(char) * (length + 1));
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i <= length; i++)
		ptr[i] = string[i];
	return (ptr);
}


/**
 *_strcmp - compare two strings
 *@first: first string to be compared
 *@second: second string to be compared
 *
 * Return: difference of the two strings
 */

int _strcmp(char *s1, char *s2)
{
	int dif = 0;
	int i;

	for (i = 0;  s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		dif = s1[i] - s2[i];
		if (dif != 0)
			return (dif);
	}

	return (dif);
}


int _strlen(char *str)
{
	int length = 0;

	while (str[length])
		length++;
	return (length);
}

/**
 *_strcat - concatenates two strings
 *@destination: string to be concatenated to
 *@source:  string to concatenate
 *
 * Return: address of the new string
 */

char *_strcat(char *destination, char *source)
{
	char *ptr = destination;

	while (*ptr)
		ptr++;

	while (*source)
	{
		*ptr = *source;
		ptr++;
		source++;
	}
	*ptr = *source;
	return (destination);
}
/**
 *_strcpy - copies a string to another buffer
 *@source: source to copy from
 *@dest: destination to copy to
 *
 * Return: void
 */

char *_strcpy(char *destination, char *source)
{
	int i = 0;

	while(source[i])
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
	return (destination);
}
