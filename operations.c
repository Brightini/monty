#include "monty.h"

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
	(void)line_num;

	temp = *stack;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - prints element at the top of a list
 * @stack: double pointer to head node of list
 * @line_num: line number of bytecode file
*/
void pint(stack_t **stack, unsigned int line_num)
{
	if (!(*stack))
	{
		printf("L%u: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: double pointer to head node of list
 * @line_num: line number of bytecode file
*/
void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (!(*stack))
	{
		printf("L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	if (!(*stack)->next)
		*stack = NULL;
	else
		*stack = (*stack)->next, (*stack)->prev = NULL;
	free(temp);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to head node of list
 * @line_num: line number of bytecode file
*/
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (!(*stack)->next)
	{
		printf("L%u: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	if (temp->next) /* when stack contains more than 2 element */
	{
		(*stack)->next = temp->next;
		temp->next->prev = *stack;
	}
	else /* when stack contains only two elements */
		(*stack)->next = NULL;
	(*stack)->prev = temp;
	temp->next = *stack;
	temp->prev = NULL;
	*stack = temp;
}
