#include "monty.h"

/**
 * mod - calculates modulus of 2 element br first element
 * @stack: stack pointer
 * @num: unused number
 */
void mod(stack_t **stack, unsigned int __attribute__((unused))num)
{
	stack_t *ptr = *stack;

	ptr->next->n %= ptr->n;
	*stack = ptr->next;
	ptr->next->prev = NULL;
	free(ptr);
}
