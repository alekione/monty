#include "monty.h"

void swap(stack_t **stack)
{
	stack_t *ptr = *stack;
	int n;

	if (ptr == NULL || ptr->next == NULL)
	{
		print_err(stack, "swap", NULL);
	}
	n = ptr->n;
	ptr->n = ptr->next->n;
	ptr->next->n = n;
	*stack = ptr;
}
