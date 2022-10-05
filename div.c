#include "monty.h"

/**
 * divide - divides the top 2 elements of the stack
 * @stack: stack pointer
 * @num: unused number
 */
void divide(stack_t **stack, unsigned int __attribute__((unused))num)
{
	stack_t *ptr = *stack;

	ptr->next->n /= ptr->n;
	*stack = ptr->next;
	ptr->next->prev = NULL;
	free(ptr);
}
