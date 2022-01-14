#include "monty.h"
/**
 * main - interprets a monty/bytecode file
 *
 * @argc: argument counter
 * @argv: arguments
 * Return: Always 0.
 */
int main(int argc, char **argv)
{

	file_open(argc, argv);

	parse_line();

	return (0);
}
/**
 * parse_line - reads and tokenizes line
 */
void parse_line(void)
{
	stack_t *head = NULL;
	char *buffer = NULL, *buffer2 = NULL, **commands;
	size_t len = 0;
	ssize_t nread;
	int line_counter = 0, i = 0, buff_std = buffstd;

	commands = malloc(buff_std * sizeof(char *));
	if (commands == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	for (line_counter = 1; (nread = getline(&buffer, &len, command_t.store_check))
			!= -1; line_counter++)
	{
		if (nread == 2)
			continue;
		buffer2 = strtok(buffer, " \n\t$");
		command_t.line = buffer;
		if (buffer2 == NULL || buffer2[0] == '#')
			continue;
		validate_push_opcode(i, line_counter, commands, buffer2, head);
		command_t.number = commands[1];
		command_t.instructions = commands;
		call_opcode(line_counter, &head);
	}
	free_all(buffer, head, commands, command_t.store_check);
}
/**
 * call_opcode - calls on struct function to find opcode and execute
 * @line_counter: line number of opcode
 * @head: pointer to list
 */
void call_opcode(int line_counter, stack_t **head)
{
	void (*f)(stack_t **stack, unsigned int line_number);

	f = select_command(command_t.instructions);
	if (f == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_counter,
			command_t.instructions[0]);
		free_all(command_t.line, *head, command_t.instructions,
			 command_t.store_check);
		exit(EXIT_FAILURE);
	}
	f(head, line_counter);
}
/**
 * validate_push_opcode - validates if push has an argument
 * @i: counter
 * @line_counter: command lin number
 * @commands: tokenized line
 * @buffer2: tokens iterator
 * @head: pointer to list
 */
void validate_push_opcode(int i, int line_counter, char **commands,
		char *buffer2, stack_t *head)
{
	for (i = 0; buffer2; i++)
	{
		commands[i] = buffer2;
		buffer2 = strtok(NULL, " \n\t$");
		if (strcmp(commands[i], "push") == 0)
		{
			if (i >= 2)
				break;
			if (buffer2 == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_counter);
				free_all(command_t.line, head, commands, command_t.store_check);
				exit(EXIT_FAILURE);
			}
		}
	}
}

