#include "monty.h"

void (*select_command(char **token))(stack_t **stack, unsigned int line_number)
{
    int i = 0;

    instruction_t op_functions[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}};

    for (; op_functions[i].opcode; i++)
    {
        if (strcmp(op_functions[i].opcode, token[0]) == 0)
            return (op_functions[i].f);
    }
    return (NULL);
}

void push(stack_t **stack, unsigned int line_number)
{
    int command_converted = 0;
    /*
    printf("string:%s", command_t.number);*/

    if (isdigit(command_t.number[0]) == 0)
    {
        fprintf(stderr, "L%d: usage: push integer", line_number);
        exit(EXIT_FAILURE);
    }
    else
    {
        command_converted = atoi(command_t.number);
        add_dnodeint(stack, command_converted);
    }
}

void pall(stack_t **stack, unsigned int line_number)
{
    (void)line_number;
    
    while (*stack)
    {
        printf("%d\n", (*stack)->n);
        *stack = (*stack)->next;
    }
}
/*
stack_t *create_node_with_data(stack_t **head,int number)
{

    stack_t *node = malloc(sizeof(stack_t));
    node->n = number;
    node->prev = NULL;
    node->next = NULL;

    return (node);
}*/