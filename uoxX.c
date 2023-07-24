#include <stdio.h>

/**
 * main - Handle the conversion specifiers
 * Return: Always 0
 */

int main(void)
{
	unsigned int number = 42;

	printf("%u\n", number);

	int number_octal = 42;

	printf("%o\n", number_octal);

	int number_hex_lower = 42;

	printf("%x\n", number_hex_lower);

	int number_hex_upper = 42;

	printf("%X\n", number_hex_upper);
	return (0);
}
