#include "monty.h"

/**
 * add - add the first two elements of the stack
 * @stack: stack with elements
 * @num: unused number
 */
void add(stack_t **stack, unsigned int __attribute__((unused))num)
{
	stack_t *ptr = *stack;

	ptr->next->n += ptr->n;
	*stack = ptr->next;
	ptr->next->prev = NULL;
	free(ptr);
	ptr = NULL;
}
