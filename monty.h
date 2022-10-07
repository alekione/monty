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
 * @format: holds the program format - stack/queue
 */
typedef struct stack_info
{
	int line_num;
	char *val;
	char *format;
} stack_info;

extern stack_info *info;

/* ========== main .c ========== */
/* processeses the file passed as the argument */
int process_file(stack_t **stack, instruction_t **instruct, char *file);

/* continues process_file function */
void process_file2(char *str, instruction_t **instruct);

/* initializes some of the arguments required by the program */
void initialize(instruction_t **instruct);

/* strips newline character from a string */
void stripstr(char **ptr);

/* ====== run_command.c ========= */
/* controls execution of opcode commands */
int run_command(stack_t **stack, instruction_t **instruct);
int run_command2(char *op, int execute, stack_t **stack,
		instruction_t **instruct);
int run_command3(char *op, int execute, stack_t **stack,
		instruction_t **instruct);

/* checks whether the command read is an opcode */
bool isopcode(char *opcode);

/* ======== isexecutable.c ========= */
/* checks whether a given opcode meets certain conditions */
bool isexecutable(char *command, stack_t *stack);

/* ====== push.c ============= */
/* adds elements on a stack */
void push(stack_t **stack, int num);
/* adds at the head/front of a stack */
void push_s(stack_t **stack, int num);
/* adds at the end/bottom of the stack */
void push_q(stack_t **stack, int num);

/* ====== other single *.c files ========= */

/* checks whether a string is a complete number */
bool isnum(char *str);

/* removes element at the top of stack */
void pop(stack_t **stack, unsigned int num);

/* swaps the first two element of stack */
void swap(stack_t **stack, unsigned int num);

/* adds the first two element of a stack */
void add(stack_t **stack, unsigned int num);

/* performs subtraction to the first elements on a stack */
void sub(stack_t **stack, unsigned int num);

/* performs division to the 1st 2 elements on a stack */
void divide(stack_t **stack, unsigned int num);

/* performs multiplication on the first 2 elements */
void mul(stack_t **stack, unsigned int num);

/* performs modulouson the first 2 elements */
void mod(stack_t **stack, unsigned int num);

/* prints the first element as a char */
void pchar(stack_t **stack, unsigned int num);

/* prints a stack as a sequence of char(s) */
void pstr(stack_t **stack, unsigned int num);

/*i interchanges the elements in a stack */
void rotl(stack_t **stack, unsigned int num);

/* reverses a stack */
void rotr(stack_t **stack, unsigned int num);

/*======== print.c ======= */
/*prints error messages */
void print_err(char *iden, char *add_info);

/* prints all elements of a stack */
void pall(stack_t **stack, unsigned int num);

/* prints the first/top element in a stack */
void pint(stack_t **stack, unsigned int num);

/* =========== free.c ======== */
/* frees all program memory */
void free_all(stack_t **stack, instruction_t **instruct);

/* frees stack memory */
void free_stack(stack_t **stack);

/* frees a string pointer */
void free_str(char **ptr);
#endif
