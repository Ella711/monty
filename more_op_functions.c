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