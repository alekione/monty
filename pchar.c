#include "monty.h"

/**
 * pchar - prints the first element of the stack as a char
 * @stack: stack pointer
 * @num: unused number
 */
void pchar(stack_t **stack, unsigned int __attribute__((unused))num)
{
	printf("%c\n", (*stack)->n);
}
