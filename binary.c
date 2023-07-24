#include <stdio.h>
/**
 * main - unsigned int num
 * convertToBinary: convert numbers to integer
 * @ b: the unsigned int argument is converted to binary
 * Return: 0 always
 */
void convertToBinary(unsigned int num)
{
	unsigned int mask = 1 << ((sizeof(unsigned int) * 8) - 1);
	/*create a mask to extract each bit*/
	int leadingZeros = 1;
	/*flag to ignore leading zeros*/
	for (int i = 0; i < sizeof(unsigned int) * 8; i++)
	{
		int bit = (num & mask) ? 1 : 0;

		/*check if the current bit is set*/
		if (leadingZeros  bit)
		{
			printf("%d", bit);
			leadingZeros = 0;
			/*set flag to false after first bit is encountered*/
		}
		mask >>= 1;
		/*shift the mask for the next bit*/
	}
}

int main(void)
{
	unsigned int num = 23;

	printf("%b\n", num);
	return (0);
}
