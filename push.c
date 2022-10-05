#include "monty.h"

/**
 * push - adds element either front or behind the stack
 * @stack: stack pointer
 * @n: int value to add to the stack
 */
void push(stack_t **stack, unsigned int n)
{
	char *stk = "stack";

	if (strcmp(info->format, stk) == 0)
		push_s(stack, n);
	else
		push_q(stack, n);
}

/**
 * push_s - add a node at the head of a linked list
 * @stack: pointer to the head of the list
 * @n: int data to add to the node
 */
void push_s(stack_t **stack, unsigned int n)
{
	stack_t *ptr, *start;

	ptr = malloc(sizeof(stack_t));
	if (ptr == NULL)
	{
		print_err("malloc", NULL);
		exit(EXIT_FAILURE);
	}
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

/**
 * push_q - adds element at the end of a stack
 * @stack: stack pointer
 * @n: element to use on the stack
 */
void push_q(stack_t **stack, unsigned int n)
{
	stack_t *ptr, *start = *stack;

	ptr = malloc(sizeof(stack_t));
	if (ptr == NULL)
	{
		print_err("malloc", NULL);
		exit(EXIT_FAILURE);
	}
	ptr->n = n;
	ptr->next = NULL;
	if (start == NULL)
	{
		ptr->prev = NULL;
		*stack = ptr;
		return;
	}
	while (start->next != NULL)
		start = start->next;
	ptr->prev = start;
	start->next = ptr;
}
