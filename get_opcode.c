#include "monty.h"

/**
 * get_ops - gets the corresponding function of opcode
 * @opcode: opcode from bytecode file
 * Return: NULL if function is not found
*/
void (*get_ops(char *opcode))(stack_t **stack, unsigned int line_num)
{
	int i = 0;

	instruction_t op_list[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL},
	};

	while (op_list[i].opcode)
	{
		if (strcmp(opcode, op_list[i].opcode) == 0)
			return (op_list[i].f);
		i++;
	}
	return (NULL);
}
