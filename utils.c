#include "monty.h"

/**
 * free_stack - frees a doubly linked list of stacks
 * @stack: the stack to free
 * Return: void
*/

void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
/**
 * is_integer - checks if a string is an integer
 * @str: the string to check
 * Return: 1 if integer, 0 if not
*/
int is_integer(char *str)
{
    int i = 0;

    if (str == NULL)
    {
        return (0);
    }

    if (str[0] == '-')
    {
        i = 1;
    }

    for (; str[i] != '\0'; i++)
    {
        if (isdigit((unsigned char) str[i]) == 0)
        {
            return (0);
        }
    }

    return (1);
}
