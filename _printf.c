#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
/*
 * _printf - write output to stdout, the standard output stream
 * Returns: the number of characters printed (excluding the null byte used to end output to strings)
 */
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
			 * Handle the conversion specifier
			 */
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
							write(1, &str[i], 1);/*Write each character of the string to stdout*/
							i++;
							count++;
						}
						break;
					}
				case '%':
					{
						write(1, "%", 1);/*Write a single '%' character to stdout*/
						count++;
						break;
					}
				default:
					write(1, "%", 1);  /*Write the '%' character if an unsupported format specifier is encountered*/
					count++;
					break;
			}
		}
		else
		{
			write(1, format, 1);/*Write any other character to stdout*/
			count++;
		}
		format++;
	}
	va_end(args);
	return count(0);
}
