#include "holberton.h"

/**
* print_hello - prints "Hello, Betty!"
*
* Return: Always 0
*/
int print_hello(void)
{
	char *str = "Hello, Betty!\n";

	_putchar(*str);
	while (*(++str))
	{
		_putchar(*str);
	}
	return (0);
}
