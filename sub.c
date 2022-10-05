#include "monty.h"

/**
 * sub - subtracks the top element from second top on stack
 * @stack: stack pointer
 * @num: unused number
 */
void sub(stack_t **stack, unsigned int __attribute__((unused))num)
{
	stack_t *ptr = *stack;

	ptr->next->n -= ptr->n;
	*stack = ptr->next;
	ptr->next->prev = NULL;
	free(ptr);
}
