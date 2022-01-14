#include "monty.h"

void mul(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;
    stack_t *counter = *stack;
    int i = 0;

    for (; counter; i++)
        counter = counter->next;
    if (i < 2 || !*stack || !(*stack)->next || !stack)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
        frees_struct(stack);
    }
    temp->next->n = temp->n * temp->next->n;
    pop(stack, line_number);
}

void mod(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;
    stack_t *counter = *stack;
    int i = 0;

    for (; counter; i++)
        counter = counter->next;
    if (i < 2 || !*stack || !(*stack)->next || !stack)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
        frees_struct(stack);
    }
    if (temp->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        frees_struct(stack);
    }
    temp->next->n = temp->next->n % temp->n;
    pop(stack, line_number);
}

void pchar(stack_t **stack, unsigned int line_number)
{

    if (!stack || !*stack)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
        frees_struct(stack);
    }
    if ((*stack)->n > 31 && (*stack)->n < 127)
    {
        putchar((*stack)->n);
        putchar('\n');
    }
    else
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
        frees_struct(stack);
    }
}
/*
void pstr(stack_t **stack, unsigned int line_number)
{

    while (*stack)
    {
        if ((*stack)->n > 31 && (*stack)->n < 127)
        {
            putchar((*stack)->n);
            putchar('\n');
        }
        *stack = (*stack)->next;
    }
}
*/