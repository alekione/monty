#include "monty.h"

/**
 * rotl - reverses a stack
 * ---1st elemnt becomes the last one and the 2nd element becomes the first
 * @stack: stack pointer
 * @num: unuswd number
 */
void rotl(stack_t **stack, unsigned int __attribute__((unused))num)
{
	stack_t *last, *ptr = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	last = *stack;
	*stack  = ptr->next;
	while (last->next != NULL)
		last = last->next;
	*stack = ptr->next;
	ptr->next->prev = NULL;
	ptr->next = NULL;
	last->next = ptr;
	ptr->prev = last;
}
