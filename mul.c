#include "monty.h"

/**
 * mul - multiply the first 2 element of stack
 * @stack: stack pointer
 * @num: unused number
 */
void mul(stack_t **stack, unsigned int __attribute__((unused))num)
{
	stack_t *ptr = *stack;

	ptr->next->n *= ptr->n;
	*stack = ptr->next;
	ptr->next->prev = NULL;
	free(ptr);
}
