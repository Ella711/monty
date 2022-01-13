#include "monty.h"

void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = NULL;
    stack_t *temp2 = NULL;
    stack_t *temp3 = NULL;
    stack_t *counter = *stack;
    int i = 0;

    for (; counter; i++)
        counter = counter->next;
    if (i < 2)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    /*
        printf("temp:%d\n", temp->n);
        printf("temp2:%d\n", temp2->n);
        printf("temp3:%d\n", temp3->n);*/
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
    if (i < 2)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    temp->next->n = temp->n + temp->next->n;
    pop(stack, line_number);
}

void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}