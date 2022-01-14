#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#define buffstd 64
/**
 * struct command_s - buffer storage
 * @number: push argument
 * @store_check: stores file check
 * @line: getline buffer
 * @instructions: tokenized opcodes
 *
 * Description: storage for buffers
 */
struct command_s
{
	char *number;
	FILE *store_check;
	char *line;
	char **instructions;
} command_t;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * select_command - selects the opcode and function
 * @line_number: number line of opcode
 * Return: function for opcode
 */
void (*select_command(char **token))(stack_t **stack,
	unsigned int line_number);

void file_open(int argc, char **argv);
void parse_line(void);
void validate_push_opcode(int i, int line_counter, char **commands,
	char *buffer2, stack_t *head);
void call_opcode(int line_counter, stack_t **head);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *create_node_with_data(stack_t **head, int number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void free_stack_t(stack_t **head);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void frees_struct(stack_t **stack);
int isdigit_str(char *token);
void free_all(char *line, stack_t *head, char **commands, FILE *check);
void sub(stack_t **stack, unsigned int line_number);
void division(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);

#endif
