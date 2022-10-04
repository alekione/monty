#include "monty.h"

/**
 * push - add a node at the head of a linked list
 * @stack: pointer to the head of the list
 * @n: int data to add to the node
 */
void push(stack_t **stack, const int n)
{
	stack_t *ptr, *start;

	if (stack == NULL)
		print_err(stack, "malloc", NULL);
	ptr = malloc(sizeof(stack_t));
	if (ptr == NULL)
		print_err(stack, "malloc", NULL);
	ptr->n = n;
	ptr->next = NULL;
	ptr->prev = NULL;
	if (*stack == NULL)
	{
		*stack = ptr;
		return;
	}
	start = *stack;
	ptr->next = start;
	start->prev = ptr;
	*stack = ptr;
}
