#include <stdio.h>
#include <stdlib.h>
#include "prefetcher.h"
#include "Buffer.h"

int main()
{
	/* code */
	FILE *fh;
	size_t size;
	long count;
	char *buff;
	int status;

	prefetcher pf;

	Buffer buffer(1000, 10);
	//buffer.Buffer(1000, 10);

	fh = fopen("helloworld.c", "rb");

	//getting size
	fseek(fh, 0, SEEK_END);
	count = ftell(fh);
	rewind(fh);

	buff = (char*) malloc(sizeof(char) * count);

	fread(buff, 1, 10, fh);
	status = pf.prefetch(buffer, fh, size, count);

	printf("Status: %d\n", status);

	return 0;
}