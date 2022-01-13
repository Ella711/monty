#include "monty.h"

void (*select_command(char **token))(stack_t **stack, unsigned int line_number)
{
    int i = 0;

    instruction_t op_functions[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {NULL, NULL}};

    for (; op_functions[i].opcode; i++)
    {
        /*printf("%s\n", op_functions[i].opcode);*/
        if (strcmp(op_functions[i].opcode, token[0]) == 0)
            return (op_functions[i].f);
    }
    /*printf("Before NULL\n");*/
    return (NULL);
}

void push(stack_t **stack, unsigned int line_number)
{
    int command_converted = 0;
    /*
    printf("string:%s", command_t.number);*/

    if (isdigit(command_t.number[0]) == 0)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
    else
    {
        command_converted = atoi(command_t.number);
        add_dnodeint(stack, command_converted);
    }
    /*printf("%d", (*stack)->n);*/
}

void pall(stack_t **stack, unsigned int line_number)
{
    const stack_t *temp = *stack;
    (void)line_number;
    
    while (temp)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
    /*printf("%d", temp->n);*/
}

void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*stack)->n);
}

void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;

    printf("Head is here before popping: %d\n", (*stack)->n);

    if (*stack == NULL)
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);

    *stack = (*stack)->next;
    free(temp);
    /*printf("Head is here: %d\n", (*stack)->n);*/
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