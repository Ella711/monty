#include "monty.h"
/**
 * select_command - function pointer to check for command
 *
 * @token: pointer with commands
 * Return: function
 */
void (*select_command(char **token))(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t op_functions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", division},
		{"mul", mul},
		{"mod", mod},
		{"#", nop},
		{"pchar", pchar},
		{"pstr", pstr},
		{NULL, NULL}};

	for (; op_functions[i].opcode; i++)
	{
		if (strcmp(op_functions[i].opcode, token[0]) == 0)
			return (op_functions[i].f);
	}
	return (NULL);
}
/**
 * push - pushes new node to stack
 *
 * @stack: poiunter to list
 * @line_number: number of line where command was found
 */
void push(stack_t **stack, unsigned int line_number)
{
	int command_converted = 0;

	if (isdigit_str(command_t.number) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(command_t.instructions);
		free(command_t.line);
		fclose(command_t.store_check);
		exit(EXIT_FAILURE);
	}
	else
	{
		command_converted = atoi(command_t.number);
		add_dnodeint(stack, command_converted);
	}
}
/**
 * pall - prints list
 *
 * @stack: poiunter to list
 * @line_number: number of line where command was found
 */
void pall(stack_t **stack, unsigned int line_number)
{
	const stack_t *temp = *stack;
	(void)line_number;

	if (!stack)
		return;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pint - prints top element
 *
 * @stack: poiunter to list
 * @line_number: number of line where command was found
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free(command_t.instructions);
		free(command_t.line);
		fclose(command_t.store_check);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pop - pops top element
 *
 * @stack: poiunter to list
 * @line_number: number of line where command was found
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free(command_t.instructions);
		free(command_t.line);
		fclose(command_t.store_check);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free(temp);
}

