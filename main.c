#include "monty.h"

stack_info *info;

int main(int argc, char *argv[])
{
	FILE *op;
	stack_info s_info;
	stack_t st, *stack = &st;
	instruction_t inst, *instruct = &inst;
	ssize_t rd;
	size_t size = 0;
	char *ptr = NULL;

	info = &s_info;
	info->line_num = 0;
	stack = NULL;
	instruct->opcode = NULL;
	if (argc != 2)
		print_err(&stack, "usage", NULL);
	op = fopen(argv[1], "r");
	if (op == NULL)
		print_err(&stack, "open", argv[1]);
	while (true)
	{
		rd = getline(&ptr, &size, op);
		if (rd == -1)
			break;
		info->line_num += 1;
		strip_args(instruct, ptr);
		run_command(&stack, &instruct);
		free(ptr);
		ptr = NULL;
	}
	return (0);
}

void free_stack(stack_t **stack)
{
	stack_t *ptr = *stack;

	while (*stack != NULL)
	{
		*stack = ptr->next;
		free(ptr);
		ptr = NULL;
		ptr = *stack;
	}
}
