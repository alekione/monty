#include "monty.h"

/**
 * swap - swaps the first two elements of the stack
 * @stack: stack of elements
 * @num: unused number
 */
void swap(stack_t **stack, unsigned int __attribute__((unused))num)
{
	stack_t *ptr = *stack;
	int n;

	n = ptr->n;
	ptr->n = ptr->next->n;
	ptr->next->n = n;
	*stack = ptr;
}
