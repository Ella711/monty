#include "monty.h"

int main(int argc, char **argv)
{
    FILE *check = NULL;
    stack_t *head = NULL;
    char *buffer = NULL, *buffer2 = NULL;
    size_t len = 0;
    ssize_t nread;
    void (*f)(stack_t **stack, unsigned int line_number);
    int line_counter = 0, buff_std = buffstd, i = 0;
    char **commands = malloc(buff_std * sizeof(char *));

    if (commands == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    if (argc == 2)
    {
        check = file_open(argv[1], commands);
        command_t.store_check = check;
    }
    else
    {
        fprintf(stderr, "USAGE: monty file\n");
        free(commands);
        return (EXIT_FAILURE);
    }
    for (line_counter = 1; (nread = getline(&buffer, &len, check)) != -1; line_counter++)
    {
        if (nread == 2)
            continue;
        /*printf("Getline: %s\nnread: %ld\n", buffer, nread);
        printf("Line counter: %d\n", line_counter);*/
        buffer2 = strtok(buffer, " \n\t$#");
        /*printf("buffer2: %s\n", buffer2);*/
        command_t.line = buffer;
        if (buffer2 == NULL)
            continue;
        for (i = 0; buffer2; i++)
        {
            commands[i] = buffer2;
            buffer2 = strtok(NULL, " \n\t$#");
            /*printf("commands[i - 1]: %s\n", commands[i]);*/
            if (strcmp(commands[i], "push") == 0)
            {
                if (i >= 2)
                    break;
                if (buffer2 == NULL)
                {
                    fprintf(stderr, "L%d: usage: push integer\n", line_counter);
                    free_all(buffer, head, commands, check);
                    exit(EXIT_FAILURE);
                }
            }
            /*printf("Commands[i]: %s\n", commands[i]);*/
        }

        command_t.number = commands[1];
        command_t.instructions = commands;
        f = select_command(commands);
        if (f == NULL)
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_counter, commands[0]);
            free_all(buffer, head, commands, check);
            exit(EXIT_FAILURE);
        }
        f(&head, line_counter);
    }
    free_all(buffer, head, commands, check);
    return (0);
}