#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int count = 0;
	/*Counter to keep track of the number of characters printed*/

	while (*format != '\0')
	{
		if (*format == '%') {
			format++;
			/*Move past the '%'
			 * Handle the conversion specifier*/
			switch (*format)
			{
				case 'c':
					/*Print a single character*/
					putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					{
						/*Print a string*/
						const char *str = va_arg(args, const char *);
						while (*str != '\0')
						{
							putchar(*str);
							str++;
							count++;
						}
						break;
					}
				case '%':
					/*Print a literal '%'*/
					putchar('%');
					count++;
					break;
				default:
					/*If an unsupported specifier is encountered, just print it as it is*/
					putchar('%');
					putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			/*Print any other characters in the format string as they are*/
			putchar(*format);
			count++;
		}
		
		format++;
	}
	
	va_end(args);
	tyreturn count;
}
int main(void)
{
	int num = 42;
	char ch = 'A';
	char str[] = "Hello, World!";

	_printf("Integer: %d\n", num);
	_printf("Character: %c\n", ch);
	_printf("String: %s\n", str);
	_printf("%% - This is a percent sign.\n");

	return 0;
}
