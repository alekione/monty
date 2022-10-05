#ifndef MONTY_H
#define MONTY_H
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stddef.h>

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

/**
 * struct stack_info - contains important details about stack
 * @line_num: file line number counter
 * @val: holds int value required by stack
 * @ptr: holds address to instruction_t pointer
 */
typedef struct stack_info
{
	int line_num;
	char *val;
	instruction_t **ptr;
} stack_info;

extern stack_info *info;

int process_file(stack_t **stack, instruction_t **instruct, char *file);
ssize_t _getline(char **pline_buf, size_t *pn, FILE *fin);
void initialize(instruction_t **instruct);
int run_command(stack_t **stack, instruction_t **instruct);
bool isexecutable(char *command, stack_t *stack);
void stripstr(char **ptr);
void push(stack_t **stack, unsigned int num);
void pop(stack_t **stack, unsigned int num);
void swap(stack_t **stack, unsigned int num);
void add(stack_t **stack, unsigned int num);
void pall(stack_t **stack, unsigned int num);
void pint(stack_t **stack, unsigned int num);
void print_err(char *iden, char *add_info);
void free_all(stack_t **stack, instruction_t **instruct);
void free_stack(stack_t **stack);
void free_str(char **ptr);
#endif
