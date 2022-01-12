#include "monty.h"

void (*select_command(char *token))(stack_t **stack, unsigned int line_number)
{
    int i = 0;

    instruction_t op_functions[] = {
        {"push", push},
        {NULL, NULL}};

    for (; op_functions[i].opcode; i++)
    {
        if (strcmp(op_functions[i].opcode, token) == 0)
            return (op_functions[i].f);    
    }
    return (NULL);
}

void push(stack_t **stack, unsigned int line_number)
{
    (void) line_number;
    /*stack_t *head = NULL;*/

    add_dnodeint_end(stack, atoi(commands));
}
/*
stack_t *create_node_with_data(int number)
{
    stack_t *node = malloc(sizeof(stack_t));
    node->n = number;
    node->prev = NULL;
    node->next = NULL;

    return (node);
}*/