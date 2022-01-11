#include "monty.h"

int main(int argc, char **argv)
{
    FILE *check = NULL;
    char *buffer = NULL, *buffer2 = NULL;
    size_t len = 0;
    ssize_t nread;
    int line_counter = 0, buff_std = buffstd, i = 0;
    char **commands = malloc(buff_std * sizeof(char *));

    if (argc == 2)
    {
        check = fopen(argv[1], "r");
        if (check == NULL)
        {
            fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
            return (EXIT_FAILURE);
        }
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
            printf("Commands[i]: %s\n", commands[i]);
            buffer2 = strtok(NULL, " ");
        }
    }
    /*
    for (; i <= nread; i++)
    {
        if (buffer[i] != " ")
        {
        }
    }*/
    
    return (0);
}