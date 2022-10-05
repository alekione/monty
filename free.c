#include "monty.h"

/**
 * free_all - frees all memory
 * @stack: stack pointer
 * @instruct: instruction_t pointer
 */
void free_all(stack_t **stack, instruction_t **instruct)
{
	free_stack(stack);
	free_str(&(*instruct)->opcode);
	free_str(&info->val);
}

/**
 * free_stack - frees a stck memory
 * @stack: stack pointer
 */
void free_stack(stack_t **stack)
{
	stack_t *ptr;

	if (*stack == NULL)
		return;
	ptr = (*stack)->next;
	while (ptr != NULL)
	{
		free(*stack);
		*stack = ptr;
		ptr = (*stack)->next;
	}
	free(*stack);
}

/**
 * free_str - free memory of a string
 * @ptr: string pointer
 */
void free_str(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

