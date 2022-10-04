#ifndef MONTY_H
#define MONTY_H
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element/node of the stack/queue
 * @next: points to the next element/node of the stack/queue
 *
 * Description: doubly linked list node structure
 * for stack, queue, LIFO, and  FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queue, LIFO and FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct stack_info
{
	int line_num;
	char *val;
} stack_info;

extern stack_info *info;

void run_command(stack_t **stack, instruction_t **instruct);
void strip_args(instruction_t *instruct, char *ptr);
void push(stack_t **stack, const int num);
void pop(stack_t **stack);
void swap(stack_t **stack);
void add(stack_t **stack);
void pall(stack_t **stack);
void pint(stack_t **stack);
void print_err(stack_t **stack, char *iden, char *add_info);
void free_stack(stack_t **stack);
#endif
