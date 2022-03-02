#include "holberton.h"
#include <stdio.h>

/**
 * wildcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 1 if identical 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
	int ast = 0;

	return (recur_wildcmp(s1, s2, ast));
}

/**
 * recur_wildcmp - recursive function to compare strings
 * @s1: first string
 * @s2: second string
 * @ast: number of asterisks
 * Return: 1 if identical 0 otherwise
 */
int recur_wildcmp(char *s1, char *s2, int ast)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s2 == '*')
		return (recur_wildcmp(s1, s2 + 1, ++ast));
	else if (*s1 != *s2 && ast > 0)
	{
		if (*s1 != '\0')
			return (recur_wildcmp(s1 + 1, s2, ast));
		return (0);
	}
	else if (*s1 != *s2 && ast == 0)
		return (0);
	else if (*s1 == *s2 && ast > 0)
	{
		if (recur_wildcmp(s1 + 1, s2 + 1, 0) == 1)
			return (recur_wildcmp(s1 + 1, s2 + 1, ast));
		return (recur_wildcmp(s1 + 1, s2, ast));
	}
	else if (*s1 == *s2 && ast == 0)
		return (recur_wildcmp(s1 + 1, s2 + 1, 0));
	return (0);
}
