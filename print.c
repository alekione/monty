#include "monty.h"

/**
 * print_err - printd error messages to stderr
 * @iden: string identifier
 * @add_info: additional info to print
 */
void print_err(char *iden, char *add_info)
{
	char *usage = "usage", *op = "open", *cmd = "command", *mallc = "malloc",
	     *mul = "mul", *md = "mod";
	char *pnt = "pint", *ad = "add", *swp = "swap", *pp = "pop", *pchr = "pchar",
	     *inv = "invalid", *unkn = "unknown", *sb = "sub", *dv = "div";

	if (strcmp(iden, inv) == 0)
		fprintf(stderr, "L%d: usage: push integer\n", info->line_num);
	else if (strcmp(iden, usage) == 0)
		fprintf(stderr, "USAGE: monty file\n");
	else if (strcmp(iden, op) == 0)
		fprintf(stderr, "Error: Can't open file %s\n", add_info);
	else if (strcmp(iden, cmd) == 0)
		fprintf(stderr, "L%d: unknown instruction %s\n",
				info->line_num, add_info);
	else if (strcmp(iden, pnt) == 0 || strcmp(iden, pchr) == 0)
		fprintf(stderr, "L%d: can't %s, stack empty\n", info->line_num, iden);
	else if (strcmp(iden, ad) == 0 || strcmp(iden, swp) == 0 ||
			strcmp(iden, sb) == 0 || strcmp(iden, dv) == 0 || strcmp(iden, mul) == 0 ||
			strcmp(iden, md) == 0)
		fprintf(stderr, "L%d: can't %s, stack too short\n", info->line_num, iden);
	else if (strcmp(iden, pp) == 0)
		fprintf(stderr, "L%d: can't pop an empty stack\n", info->line_num);
	else if (strcmp(iden, mallc) == 0)
		fprintf(stderr, "Error: malloc failed\n");
	else if (strcmp(iden, unkn) == 0)
		fprintf(stderr, "L%d: unknown instruction %s\n", info->line_num, add_info);
}

/**
 * pall - prints elements of a stack from the top
 * @stack: stack pointer
 * @num: unused number
 */
void pall(stack_t **stack, unsigned int __attribute__((unused))num)
{
	stack_t *ptr = *stack;

	while (ptr != NULL)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 * pint - prints the first element of the stack
 * @stack: stack pointer
 * @num: unused number
 */
void pint(stack_t **stack, unsigned int __attribute__((unused))num)
{
	printf("%d\n", (*stack)->n);
}
