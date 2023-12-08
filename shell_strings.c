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

int _strcmp(char *s, char *ss)
{
	int cmp;

	cmp = (int)*s - (int)*ss;

	while(s)
	{
		if (s != ss)
			break;
		s++;
		ss++;
		cmp = (int)*s - (int)*ss;
	}
	return (cmp);

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

void _strcpy(char *source, char *dest)
{
	int i = 0;

	for (; source[i] != '\0'; i++)
		dest[i] = source[i];
	dest[i] = '\0';
}

