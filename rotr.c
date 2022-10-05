#include "monty.h"

/**
 * rotr - reverses a stack
 * @stack: stack pointer
 * @num: unused number
 */
void rotr(stack_t **stack, unsigned int __attribute__((unused))num)
{
	stack_t *ptr, *last, *next;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	*stack = last;
	ptr = *stack;
	while (ptr != NULL)
	{
		next = ptr->prev;
		ptr->prev = ptr->next;
		ptr->next = next;
		ptr = next;
	}
}
