#include "monty.h"

FILE *file_open(char *argv)
{
    FILE *check = NULL;
    check = fopen(argv, "r");

    if (check == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv);
        exit(EXIT_FAILURE);
    }
    return (check);
}