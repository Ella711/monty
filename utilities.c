#include "monty.h"
/**
 * file_open - opens bytecode file
 * @argc: argument counter
 * @argv: arguements
 * Return: file pointer
 */
void file_open(int argc, char **argv)
{
	FILE *check = NULL;

	if (argc == 2)
	{
		check = fopen(argv[1], "r");
		if (check == NULL)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		command_t.store_check = check;
	}
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * isdigit_str - checks if a string contains all numbers
 * @token: string
 * Return: 0 if no number, 1 if numbers
 */
int isdigit_str(char *token)
{
	int i = 0;

	if (token == NULL)
		return (0);

	if (token[i] == '-')
		i++;

	while (token[i])
	{
		if (isdigit(token[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
/**
 * frees_struct - frees elements
 *
 * @stack: pointer to list
 */
void frees_struct(stack_t **stack)
{
	free(command_t.instructions);
	free(command_t.line);
	free_stack_t(stack);
	fclose(command_t.store_check);
	exit(EXIT_FAILURE);
}
/**
 * free_all - frees most elements
 *
 * @line: getline buffer
 * @head: pointer to list
 * @commands: pointer to commands
 * @check: file pointer
 */
void free_all(char *line, stack_t *head, char **commands, FILE *check)
{
	free(line);
	free_stack_t(&head);
	free(commands);
	fclose(check);
}

