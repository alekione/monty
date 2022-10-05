#include "monty.h"

/**
 * isexecutable - checks whether the passed commands can be executed
 * @command: opcode command
 * @stack: stack pointer
 * Return: true or false
 */
bool isexecutable(char *command, stack_t *stack)
{
	char *pnt = "pint", *pp = "pop", *swp = "swap", *ad = "add";

	if (stack == NULL)
	{
		if (strcmp(command, pnt) == 0)
		{
			print_err("pint", NULL);
			return (false);
		}
		if (strcmp(command, pp) == 0)
		{
			print_err("pop", NULL);
			return (false);
		}
	}
	if (stack == NULL || stack->next == NULL)
	{
		if (strcmp(command, swp) == 0)
		{
			print_err("swap", NULL);
			return (false);
		}
		if (strcmp(command, ad) == 0)
		{
			print_err("add", NULL);
			return (false);
		}
	}
	return (true);
}
