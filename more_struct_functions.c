#include "monty.h"
/**
 * swap - swaps top two elements
 *
 * @stack: poiunter to list
 * @line_number: number of line where command was found
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	stack_t *temp2 = NULL;
	stack_t *temp3 = NULL;
	stack_t *counter = *stack;
	int val = 0, i = 0;

	for (; counter; i++)
		counter = counter->next;
	if (i < 2 || !*stack || !(*stack)->next || !stack)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		frees_struct(stack);
	}
	if (i == 2)
	{
		val = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = val;
	}
	else
	{
		temp = *stack;
		temp2 = (*stack)->next;
		temp3 = (*stack)->next->next;

		temp2->next = *stack;
		temp3->prev = *stack;
		temp2->prev = NULL;
		temp->next = temp3;
		temp->prev = temp2;
		*stack = temp2;
	}
}

/**
 * add - adds top two elements, stores sum in second
 * to top and pops top element
 *
 * @stack: poiunter to list
 * @line_number: number of line where command was found
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	stack_t *counter = *stack;
	int i = 0;

	for (; counter; i++)
		counter = counter->next;
	if (i < 2 || !*stack || !(*stack)->next || !stack)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		frees_struct(stack);
	}
	temp->next->n = temp->n + temp->next->n;
	pop(stack, line_number);
}
/**
 * nop - does nothing
 *
 * @stack: poiunter to list
 * @line_number: number of line where command was found
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
/**
 * sub - subs top two elements, stores sum in second
 * to top and pops top element
 *
 * @stack: poiunter to list
 * @line_number: number of line where command was found
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	stack_t *counter = *stack;
	int i = 0;

	for (; counter; i++)
		counter = counter->next;
	if (i < 2 || !*stack || !(*stack)->next || !stack)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		frees_struct(stack);
	}
	temp->next->n = temp->next->n - temp->n;
	pop(stack, line_number);
}
/**
 * division - divides top two elements, stores sum in
 * second to top and pops top element
 *
 * @stack: poiunter to list
 * @line_number: number of line where command was found
 */
void division(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	stack_t *counter = *stack;
	int i = 0;

	for (; counter; i++)
		counter = counter->next;
	if (i < 2 || !*stack || !(*stack)->next || !stack)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		frees_struct(stack);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		frees_struct(stack);
	}
	temp->next->n = temp->next->n / temp->n;
	pop(stack, line_number);
}

