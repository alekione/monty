#include "monty.h"

void run_command(stack_t **stack, instruction_t **instruct)
{
	char *op, *psh = "push", *pll = "pall", *pnt = "pint", *pp = "pop",
	     	*swp = "swap", *ad = "add", *zero = "0";
	instruction_t *inst = *instruct;
	int val;

	op = inst->opcode;
	if (strcmp(op, psh) == 0 || strcmp(op, pp) == 0)
	{
		if (info->val == NULL)
			print_err(stack, "invalid", NULL);
		val = atoi(info->val);
		if (val == 0 && strcmp(info->val, zero) != 0)
		{
			print_err(stack, "invalid", NULL);
		}
	}
	if (strcmp(op, psh) == 0)
		push(stack, val);
	if (strcmp(op, pll) == 0)
		pall(stack);
	if (strcmp(op, pnt) == 0)
		pint(stack);
	if (strcmp(op, pp) == 0)
		pop(stack);
	if (strcmp(op, swp) == 0)
		swap(stack);
	if (strcmp(op, ad) == 0)
		add(stack);
}
