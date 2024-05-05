#include "head.h"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    if (isatty(STDIN_FILENO))
    {
        int_mode();
    }
    else
    {
        non_int_mode(stdin);
    }
    return (0);
}

