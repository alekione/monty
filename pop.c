#include "monty.h"

/**
 * pop - removes/deletes element at the top of the stack
 * @stack: stack of linked list
 */
void pop(stack_t **stack)
{
	stack_t *ptr;

	ptr = *stack;
	if (ptr == NULL)
		return;
	*stack = ptr->next;
	if (ptr->next != NULL)
		ptr->next->prev = NULL;
	free(ptr);
	ptr = NULL;
}
