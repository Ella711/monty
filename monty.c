#include "monty.h"

int main(int argc, char **argv)
{
    FILE *check = NULL;
    char *buffer = NULL;
    size_t len = 0;
    ssize_t nread;
    /*int i = 0;*/

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
    nread = getdelim(&buffer, &len, ' ', check);
    if (nread == -1)
    {
        perror("error: \n");
        return (EXIT_FAILURE);
    }
    /*
    for (; i <= nread; i++)
    {
        if (buffer[i] != " ")
        {
        }
    }*/
    printf("%s", buffer);
    return (0);
}