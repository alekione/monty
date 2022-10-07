#include "monty.h"

/**
 * rotr - reverses a stack
 * @stack: stack pointer
 * @num: unused number
 */
void rotr(stack_t **stack, unsigned int __attribute__((unused))num)
{
	stack_t *ptr, *last;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	last = *stack;
	ptr = *stack;
	while (last->next != NULL)
		last = last->next;
	*stack = ptr->next;
	ptr->next->prev = NULL;
	ptr->next = NULL;
	ptr->prev = last;
	last->next = ptr;
}
