#include "monty.h"

/**
 * isnum - checks whether a string is a number
 * @str: string to compare
 * Return: true or false
 */
bool isnum(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}
	return (true);
}
