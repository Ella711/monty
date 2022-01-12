#include "monty.h"

int main(int argc, char **argv)
{
    FILE *check = NULL;
    /*stack_t *nodo = NULL;*/
    char *buffer = NULL, *buffer2 = NULL;
    size_t len = 0;
    ssize_t nread;
    void (*f)(stack_t * *stack, unsigned int line_number);
    int line_counter = 0, buff_std = buffstd, i = 0;
    char **commands = malloc(buff_std * sizeof(char *));

    if (argc == 2)
    {
        check = file_open(argv[1]);
    }
    else
    {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }
    for (line_counter = 1; (nread = getline(&buffer, &len, check)) != -1; line_counter++)
    {
        printf("Getline: %s\n", buffer);
        printf("Line counter: %d\n", line_counter);
        buffer2 = strtok(buffer, " ");
        for (i = 0; buffer2; i++)
        {
            commands[i] = buffer2;
            printf("Commands[i]: %s", commands[i]);
            buffer2 = strtok(NULL, " ");
        }
        f = select_command(commands[0]);
        if (f == NULL)
        {
            printf("a");
        }
        
        /*nodo = create_node_with_data(commands[1]);*/

        printf("Commands: %s", commands[1]);
    }

    return (0);
}