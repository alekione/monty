#include "monty.h"
#define _GNU_SOURCE

stack_info *info;

/**
 * main - program entry point
 * @argc: argv counter
 * @argv: cmd arguments
 * Return: 0 on success 1 on fail
 */
int main(int argc, char *argv[])
{
	stack_info s_info;
	stack_t st, *stack = &st;
	instruction_t inst, *instruct = &inst;
	int ret;

	if (argc != 2)
	{
		print_err("usage", NULL);
		return (EXIT_FAILURE);
	}
	info = &s_info;
	initialize(&instruct);
	info->line_num = 0;
	stack = NULL;
	ret = process_file(&stack, &instruct, argv[1]);
	free_all(&stack, &instruct);
	return (ret);
}

/**
 * process_file - processes a passed monty file
 * @stack: pointer to stack
 * @instruct: instruction pointer
 * @file: filename
 * Return: 0 on success 1 on fail
 */
int process_file(stack_t **stack, instruction_t **instruct, char *file)
{
	FILE *stream;
	char *line = NULL, *token, *str;
	size_t len = 0, count = 0;
	ssize_t nread;
	int ret = EXIT_SUCCESS;

	stream = fopen(file, "r");
	if (stream == NULL)
	{
		print_err("open", file);
		return (EXIT_FAILURE);
	}
	while ((nread = getline(&line, &len, stream)) != -1)
	{
		info->line_num += 1;
		str = line;
		stripstr(&str);
		token = strtok(str, " ");
		count = 0;
		while (count < 2)
		{
			if (count == 0 && token != NULL)
				(*instruct)->opcode = strdup(token);
			if (count != 0 && token != NULL)
				info->val = strdup(token);
			token = strtok(NULL, " ");
			count++;
		}
		free_str(&line);
		if ((*instruct)->opcode == NULL)
			continue;
		ret = run_command(stack, instruct);
		if (ret == EXIT_FAILURE)
			break;
	}
	free_str(&line);
	fclose(stream);
	return (ret);
}

/**
 * initialize - initializes data variables and allocates the required memory
 * @instruct: instruction pointer
 */
void initialize(instruction_t **instruct)
{
	(*instruct)->opcode = NULL;
	info->val = NULL;
	info->ptr = instruct;
}

/**
 * stripstr - strrips newline character from a string
 * @str: string to strip
 */
void stripstr(char **str)
{
	char *ptr = *str, *nstr;

	if (ptr == NULL)
		return;
	nstr = strtok(ptr, "\n");
	*str = nstr;
}
