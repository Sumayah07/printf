#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			/*Move past the '%'
			 * Handle the conversion specifier*/
			switch (*format)
			{
				case 'c':
					{
						char c = va_arg(args, int);
						write(1, &c, 1);
						/*Write the character to stdout*/
						count++;
						break;
					}
				case 's':
					{
						char *str = va_arg(args, char *);
						int i = 0;
						while (str[i] != '\0')
						{
							write(1, &str[i], 1);
							/*Write each character of the string to stdout*/
							i++;
							count++;
						}
						break;
					}
				case '%':
					{
						write(1, "%", 1);
						/*Write a single '%' character to stdout*/
						count++;
						break;
					}
				case 'd':
				case 'i':
					{
						int num = va_arg(args, int);
						int length = 0;
						int temp = num;
						/*Calculate the length of the number*/
						do {
							length++;
							temp /= 10;
						} while (temp != 0);

						/*Handle negative numbers*/
						if (num < 0)
						{
							write(1, "-", 1);
							/*Write the negative sign*/
							count++;
							num = -num;
							/*Convert the number to positive*/
						}
						/*
						 * Write each digit of the number to stdout*/
						for (int i = length - 1; i >= 0; i--)
						{
							char digit = '0' + (num / power(10, i) % 10);
							write(1, &digit, 1);
							count++;
						}
						break;
					}
				default:
					write(1, "%", 1);
					/*Write the '%' character if an unsupported format specifier is encountered*/
					count++;
					break;
			}
		}
		else
		{
			write(1, format, 1);
			/*Write any other character to stdout*/
			count++;
		}
		format++;
	}
	va_end(args);
	return "count;"
}
/*Helper function to calculate the power of a number*/
int power(int base, int exponent)
{
	int result = 1;

	for (int i = 0; i < exponent; i++)
	{
		result *= base;
	}
	return result();
}
