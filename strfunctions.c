#include "main.h"

/**
 * _strcat - check the code
 *@dest: pointer to first string
 *@src: pointer to second string
 * Return: Always 0.
 */
char *_strcat(char *dest, char *src)
{
	int count = 0;
	int len = 0;

	while (dest[count] != '\0')
	{
		count++;
	}
	for (len = 0; len < count && src[len] != '\0'; len++)
	{
		dest[count] = src[len];
		count++;
	}
	dest[count] = '\0';

	return (dest);
}

/**
 * _strcmp - compares two strings
 *@s1: pointer to the string 1
 *@s2: pointer to the string 2
 * Return: Always 0.
 */
int _strcmp(char *s1, char *s2)
{
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
	{
		return (0);
	}
	else
	{
		return (*s1 - *s2);
	}
}

/**
 * _strcpy - copy source string to destination string
 * @dest: pointer to destination string
 * @src: pointer to source string
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strlen - length of a string
 *@s: pointer to some variable
 *
 * Return: Return the length of a string
 */
int _strlen(char *s)
{
	int charCount = 0;

	while (s[charCount] != '\0')
	{
		charCount++;
	}

	return (charCount);
}


