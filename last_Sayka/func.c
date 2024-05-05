#include "head.h"

void int_mode(void)
{
    char buffer[BUFFER_SIZE];

    while (1)
    {
        printf("$ ");
        fflush(stdout);
        if (!read_command(buffer))
            break;

        process_input(buffer);
    }
}

void non_int_mode(FILE *stream)
{
    char buffer[BUFFER_SIZE];
    int readStatus;

    (void)stream;

    while (1)
    {
        readStatus = read_command(buffer);
        if (!readStatus)
            break;

        process_input(buffer);
    }
}

