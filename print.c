#include "monty.h"

/**
 * print_err - printd error messages to stderr
 * @stack: stack pointer
 * @iden: string identifier
 * @add_info: additional info to print
 */
void print_err(stack_t **stack, char *iden, char *add_info)
{
	char *usage = "usage", *op = "open", *cmd = "command";
	char *pint = "pint";
	
	if (strcmp(iden, usage) == 0)
		fprintf(stderr, "Usage: monty file\n");
	else if (strcmp(iden, op) == 0)
		fprintf(stderr, "Error: Can't open file %s\n", add_info);
	else if (strcmp(iden, cmd) == 0)
		fprintf(stderr, "L%d: unknown instruction %s\n",
				info->line_num, add_info);
	else if (strcmp(iden, pint) == 0)
		fprintf(stderr, "L%d: can't pint, stack empty\n", info->line_num);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * pall - prints elements of a stack from the top
 * @stack: stack pointer
 */
void pall(stack_t **stack)
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
 */
void pint(stack_t **stack)
{
	stack_t *ptr = *stack;
	if (*stack == NULL)
		print_err(stack, "pint", NULL);
	printf("%d\n", ptr->n);
}
