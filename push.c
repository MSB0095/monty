#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode in the file
 * Return: void
*/

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	(void)line_number;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = GBL_ARG(0, 0);
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}
