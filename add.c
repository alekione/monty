#include "monty.h"

void add(stack_t **stack)
{
	stack_t *ptr = *stack;

	if (ptr == NULL || ptr->next == NULL)
	{
		print_err(stack, "add", NULL);
	}
	ptr->next->n += ptr->n;
	*stack = ptr->next;
	ptr->next->prev = NULL;
	free(ptr);
	ptr = NULL;
}
