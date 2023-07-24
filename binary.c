#include <stdio.h>
#include <stdlib.h>
/*
 *convertToBinary: the unsigned int argument is converted to binary
 * @ b: the unsigned int argument is converted to binary
 * main - unsigned int num
 */
void convertToBinary(unsigned int num)
{
	int binary[32]; /*assuming max number size is 32 bits*/
	int i = 0;

	while (num > 0)
	{
		binary[i] = num % 2;
		num = num / 2;
		i++;
	}
	for (int j = i - 1; j >= 0; j--)
	{
		printf("%d", binary[j]);
	}
}

int main(void)
{
	unsigned int num = 123;

	printf("%b\n", num);
	return (0);
}
