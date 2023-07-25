#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

char buffer[MAX_BUFFER_SIZE];
int bufferIndex = 0;

void write_data(const char* data)
{
	int dataLen = strlen(data);

	/*Check if the current buffer combined with new data exceeds the maximum buffer size*/
	if ((bufferIndex + dataLen) >= MAX_BUFFER_SIZE)
	{
		write_buffer();
	}

	/*Copy new data to the buffer*/
	strcpy(buffer + bufferIndex, data);

	/*Update the buffer index*/
	bufferIndex += dataLen;
}

void write_buffer()
{
	/*Write the buffer contents to a file or stream using the "write" function
	 * Example: write(fd, buffer, bufferIndex);*/
	printf("Writing: %s\n", buffer);

	/*Reset the buffer index*/
	bufferIndex = 0;
}

int main(void)
{
	write_data("This is some data");
	write_data(" that needs to be written");
	write_data(" in chunks to optimize performance");
	/*After the last call to write_data, make sure to write any remaining data in the buffer*/
	write_buffer();
	return (0);
}
