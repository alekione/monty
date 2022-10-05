#include "monty.h"

/**
 * pop - removes/deletes element at the top of the stack
 * @stack: stack of linked list
 * @num: unused number
 */
void pop(stack_t **stack, unsigned int __attribute__((unused))num)
{
	stack_t *ptr;

	ptr = *stack;
	*stack = ptr->next;
	if (ptr->next != NULL)
		ptr->next->prev = NULL;
	free(ptr);
	ptr = NULL;
}
