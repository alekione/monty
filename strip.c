#include "monty.h"

void strip_args(instruction_t *instruct, char *ptr)
{
	int i, j, ind, count = 0, len = strlen(ptr);
	char str[20];

	for (i = 0; i < len && count < 2; i++)
	{
		if (ptr[i] != ' ')
		{
			for (ind = 0; ptr[i] != ' '; ind++, i++)
			{
				if (ind == 19)
					break;
				str[ind] = ptr[i];
			}
			for (j = 0; j < ind; j++)
			{
				if (str[j] == 10)
					str[j] = '\0';
			}
			str[ind] = '\0';
			if (count == 0)
				instruct->opcode = strdup(str);
			else
				info->val = strdup(str);
			count++;
		}
	}
}
