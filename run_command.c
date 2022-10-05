#include "monty.h"

/**
 * run_command - controls all function/ opcode calls
 * @stack: stack pointer
 * @instruct: instruction pointer
 * Return: success or fail 0 or 1
 */
int run_command(stack_t **stack, instruction_t **instruct)
{
	char *op, *psh = "push", *pll = "pall", *zero = "0", *no = "nop";
	instruction_t *inst = *instruct;
	unsigned int val = 0, execute = 0;

	op = inst->opcode;
	if (strcmp(op, psh) == 0)
	{
		if (info->val == NULL)
			print_err("invalid", NULL);
		else
		{
			val = atoi(info->val);
			if (val == 0 && strcmp(info->val, zero) != 0)
				print_err("invalid", NULL);
			else
				execute = 1;
			inst->f = push;
		}
	}
	else if (strcmp(op, pll) == 0)
	{
		execute = 1;
		inst->f = pall;
	}
	else if (strcmp(op, no) == 0)
		execute = -1;
	else
		execute = run_command2(op, execute, stack, &inst);
	free_str(&inst->opcode);
	free_str(&info->val);
	if (execute == 0)
		return (EXIT_FAILURE);
	if (execute == 1)
		inst->f(stack, val);
	return (EXIT_SUCCESS);
}

/**
 * run_command2 - extends run_command function
 * @op: opcode characters
 * @execute: val to determine command execution
 * @stack: stack pointer
 * @instruct: instruction pointer
 * Return: 0 or 1 for execute
 */
int run_command2(char *op, int execute, stack_t **stack,
		instruction_t **instruct)
{
	char *pp = "pop", *swp = "swap", *ad = "add", *pnt = "pint";
	instruction_t *inst = *instruct;

	if (strcmp(op, pp) == 0 && isexecutable(pp, *stack))
	{
		execute = 1;
		inst->f = pop;
	}
	else if (strcmp(op, swp) == 0 && isexecutable(swp, *stack))
	{
		execute = 1;
		inst->f = swap;
	}
	else if (strcmp(op, ad) == 0 && isexecutable(ad, *stack))
	{
		execute = 1;
		inst->f = add;
	}
	else if (strcmp(op, pnt) == 0 && isexecutable(pnt, *stack))
	{
		execute = 1;
		inst->f = pint;
	}
	else
		print_err("unknown", inst->opcode);
	return (execute);
}
