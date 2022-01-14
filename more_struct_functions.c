#include "monty.h"

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
 * sum_dlistint - returns the sum of all the data (n) of a
 * dlistint_t linked list.
 *
 * @head: pointer to linked list
 * Return: if the list is empty, return 0
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

void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

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