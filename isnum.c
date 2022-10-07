#include "monty.h"

/**
 * isnum - checks whether a string is a number
 * @str: string to compare
 * Return: true or false
 */
bool isnum(char *str)
{
	int i = 0;
	bool isnegative = false;

	if (str[i] == '-')
	{
		isnegative = true;
		i = 1;
	}
	for (; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}
	if (isnegative && i > 1)
		return (true);
	if (!(isnegative) && i != 0)
		return (true);
	return (false);
}
