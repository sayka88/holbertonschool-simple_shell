User
#include "main.h"

/**
 * print_hello - prints "Hello, Betty!"
 *
 * Return: Always 0
 */
int print_hello(void)
{
    char *str = "Hello, Betty!\n";

    while (*str)
    {
        _putchar(*str);
        str++;
    }
    return (0);
}

int main(void)
{
    print_hello();
    return (0);
}
