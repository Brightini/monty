#include "monty.h"
#include <ctype.h>

/**
 * _isdigit - checks if string is a number
 * @str: (char *) string
 * Return: 1 if string is a number, otherwise -1
*/
int _isdigit(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (!(isdigit(str[i])))
			return (-1);
		i++;
	}
	return (1);
}

/**
 * push - pushes an element to the stack
 * @stack: double pointer to head node of list
 * @line_num: line number of bytecode file
*/
void push(stack_t **stack, unsigned int line_num)
{
	stack_t *new_node;
	int data;

	new_node = malloc(sizeof(size_t));
	if (!new_node)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (!monty.arg || (_isdigit(monty.arg) == -1))
	{
		printf("L%u: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	data = atoi(monty.arg);
	new_node->n = data;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (!(*stack))
	{
		(*stack) = new_node;
		return;
	}
	/* if stack is not NULL */
	new_node->next = (*stack);
	(*stack)->prev = new_node;
	(*stack) = new_node;
}

/**
 * pall - prints all elements in a list
 * @stack: double pointer to head node of list
 * @line_num: line number of bytecode file
*/
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (!(*stack))
		return;

	if (monty.arg)
	{
		printf("L%u: usage: pall\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp = (*stack);
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
