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
	if (!(isopcode(op)))
		print_err("unknown", inst->opcode);
	else if (strcmp(op, psh) == 0)
	{
		if (info->val == NULL || !(isnum(info->val)))
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
	char *pp = "pop", *swp = "swap", *ad = "add", *pnt = "pint", *sb = "sub",
	     *stk = "stack", *que = "queue";
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
	else if (strcmp(op, sb) == 0 && isexecutable(sb, *stack))
	{
		execute = 1;
		inst->f = sub;
	}
	else if (strcmp(op, stk) == 0 || strcmp(op, que) == 0)
	{
		execute = -1;
		strcmp(op, stk) == 0 ? (info->format = "stack") : (info->format = "queue");
	}
	else
		execute = run_command3(op, execute, stack, instruct);
	return (execute);
}

/**
 * run_command2 - extends run_command function
 * @op: opcode characters
 * @execute: val to determine command execution
 * @stack: stack pointer
 * @instruct: instruction pointer
 * Return: 0 or 1 for execute
 */
int run_command3(char *op, int execute, stack_t **stack,
		instruction_t **instruct)
{
	char *dv = "div", *ml = "mul", *md = "mod", *pchr = "pchar", *psr = "pstr",
	     *rtl = "rotl", *rt = "rotr";

	if ((strcmp(op, dv) == 0 && isexecutable(dv, *stack)) ||
		(strcmp(op, md) == 0 && isexecutable(md, *stack)))
	{
		if ((*stack)->n == 0)
			fprintf(stderr, "L%d: division by zero\n", info->line_num);
		else
			execute = 1;
		strcmp(op, dv) == 0 ? ((*instruct)->f = divide) : ((*instruct)->f = mod);
	}
	else if (strcmp(op, ml) == 0 && isexecutable(ml, *stack))
	{
		execute = 1;
		(*instruct)->f = mul;
	}
	else if (strcmp(op, pchr) == 0 && isexecutable(pchr, *stack))
	{
		if ((*stack)->n < 0 || (*stack)->n > 127)
			fprintf(stderr, "L%d: can't pchar, value out of range\n", info->line_num);
		else
			execute = 1;
		(*instruct)->f = pchar;
	}
	else if (strcmp(op, psr) == 0 || strcmp(op, rtl) == 0)
	{
		execute = 1;
		strcmp(op, psr) == 0 ? ((*instruct)->f = pstr) : ((*instruct)->f = rotl);
	}
	else if (strcmp(op, rt) == 0)
	{
		execute = 1;
		(*instruct)->f = rotr;
	}
	return (execute);
}
/**
 * isopcode - checks whether a given string is an opcode
 * @opcode: char opcode
 * Return: true or false
 */
bool isopcode(char *opcode)
{
	char *cmd[] = {"push", "pall", "pint", "pop", "swap", "add", "nop",
		"sub", "div", "mul", "mod", "pchar", "pstr", "rotl", "rotr",
		"queue", "stack", NULL};
	int i;

	for (i = 0; cmd[i] != NULL; i++)
	{
		if (strcmp(opcode, cmd[i]) == 0)
			return (true);
	}
	return (false);
}
