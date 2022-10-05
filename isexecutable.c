#include "monty.h"

/**
 * isexecutable - checks whether the passed commands can be executed
 * @cmd: opcode command
 * @stack: stack pointer
 * Return: true or false
 */
bool isexecutable(char *cmd, stack_t *stack)
{
	char *pnt = "pint", *pp = "pop", *swp = "swap", *ad = "add", *sb = "sub",
	     *dv = "div", *mul = "mul", *md = "mod", *pchr = "pchar";

	if (stack == NULL)
	{
		if (strcmp(cmd, pnt) == 0)
			print_err("pint", NULL);
		if (strcmp(cmd, pp) == 0)
			print_err("pop", NULL);
		if (strcmp(cmd, pchr) == 0)
			print_err("pchar", NULL);
		if (strcmp(cmd, pnt) == 0 || strcmp(cmd, pp) == 0 ||
			strcmp(cmd, pchr) == 0)
			return (false);
	}
	if (stack == NULL || stack->next == NULL)
	{
		if (strcmp(cmd, swp) == 0)
			print_err("swap", NULL);
		if (strcmp(cmd, ad) == 0)
			print_err("add", NULL);
		if (strcmp(cmd, sb) == 0)
			print_err("sub", NULL);
		if (strcmp(cmd, dv) == 0)
			print_err("div", NULL);
		if (strcmp(cmd, mul) == 0)
			print_err("mul", NULL);
		if (strcmp(cmd, md) == 0)
			print_err("mod", NULL);
		if (strcmp(cmd, swp) == 0 || strcmp(cmd, ad) == 0 ||
			strcmp(cmd, sb) == 0 || strcmp(cmd, dv) == 0 || strcmp(cmd, mul) == 0 ||
			strcmp(cmd, md) == 0)
			return (false);
	}
	return (true);
}
