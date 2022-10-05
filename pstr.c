#include "monty.h"

/**
 * pstr - converts element of a stack into char(s) and prints them
 * @stack: stack pointer
 * @num: unused number
 */
void pstr(stack_t **stack, unsigned int __attribute__((unused))num)
{
	stack_t *ptr = *stack;
	int val;

	if (ptr == NULL)
	{
		printf("\n");
		return;
	}
	while (ptr != NULL)
	{
		val = ptr->n;
		if (val < 1 || val > 127)
			break;
		printf("%c", val);
		ptr = ptr->next;
	}
	printf("\n");
}
