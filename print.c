#include "monty.h"

/**
 * print_err - printd error messages to stderr
 * @iden: string identifier
 * @add_info: additional info to print
 */
void print_err(char *iden, char *add_info)
{
	char *usage = "usage", *op = "open", *cmd = "command", *mallc = "malloc";
	char *pnt = "pint", *ad = "add", *swp = "swap", *pp = "pop",
	     *inv = "invalid", *unkn = "unknown";

	if (strcmp(iden, inv) == 0)
		fprintf(stderr, "L%d: usage: push integer\n", info->line_num);
	else if (strcmp(iden, usage) == 0)
		fprintf(stderr, "USAGE: monty file\n");
	else if (strcmp(iden, op) == 0)
		fprintf(stderr, "Error: Can't open file %s\n", add_info);
	else if (strcmp(iden, cmd) == 0)
		fprintf(stderr, "L%d: unknown instruction %s\n",
				info->line_num, add_info);
	else if (strcmp(iden, pnt) == 0)
		fprintf(stderr, "L%d: can't pint, stack empty\n", info->line_num);
	else if (strcmp(iden, ad) == 0)
		fprintf(stderr, "L%d: can't add, stack too short\n", info->line_num);
	else if (strcmp(iden, swp) == 0)
		fprintf(stderr, "L%d: can't swap, stack too short\n", info->line_num);
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
