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
        check = file_open(argv[1]);
    else
    {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }
    for (line_counter = 1; (nread = getline(&buffer, &len, check)) != -1; line_counter++)
    {
        
        /*printf("Getline: %s\n", buffer);
        printf("Line counter: %d\n", line_counter);*/
        buffer2 = strtok(buffer, " \n\t$");
        for (i = 0; buffer2; i++)
        {
            commands[i] = buffer2;
            buffer2 = strtok(NULL, " \n\t$");
            if (i > 2)
            {
                fprintf(stderr, "More than one instruction per line\n");
                free(buffer);
                free(commands);
                fclose(check);
                return (0);
            }
            /*printf("Commands[i]: %s\n", commands[i]);*/
        }
        command_t.number = commands[1];
        f = select_command(commands);
        if (f == NULL)
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_counter, commands[0]);
            free(buffer);
            free(commands);
            fclose(check);
            return (0);
        }
        f(&head, line_counter);
        
    }
    free_stack_t(&head);
    free(commands);
    free(buffer);
    fclose(check);
    return (0);
}