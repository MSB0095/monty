#include "monty.h"

/**
 * interpret - a function to interpret a monty file
 * @file: the monty file
 * Return: 0 on success
**/
int interpret(FILE *file)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	char *opcode;
	int i = 0;
	instruction_t opcodes[] = {{"push", push},
	{"pall", pall}, {"pint", pint}, {"pop", pop}, {"swap", swap},
	{NULL, NULL}
	};

	GBL_ARG(0, 1);

	read = getline(&line, &len, file);
	while ((read) != -1)
	{
		line_number++;
		opcode = strtok(line, " \n");
		if (opcode == NULL || opcode[0] == '#')
		{
			read = getline(&line, &len, file);
			continue;
		}
		if (strcmp(opcode, "push") == 0)
		{
			char *arg = strtok(NULL, " \n");

			while (arg != NULL && *arg == '\0')
			{
				arg = strtok(NULL, " \n");
			}
			if (arg == NULL || !is_integer(arg))
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			GBL_ARG(atoi(arg), 1);
		}
		for (i = 0; opcodes[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, opcodes[i].opcode) == 0)
			{
				opcodes[i].f(&stack, line_number);
				break;
			}
		}
		if (opcodes[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
		read = getline(&line, &len, file);
	}
	free(line);
	fclose(file);
	free_stack(stack);
	return (0);
}
