#include <prefetcher.h>
#include <stdlib.h>

int prefetcher::prefetch(Buffer *const buff, FILE *fh, size_t size, size_t count){
	int check, lastposition;
	char *lastPageData;
	bool checkData;
	char *data;
	size_t result;

	fpos_t previous_pos;

	// validating the file handler
	if(fh == NULL){
		return -1;
	}

	//storing current position of the file
	fgetpos(fh, &previous_pos);


	//reading data from the backing store
	data = (char*) malloc(sizeof(char) * count);

	if(data == NULL) {
		throw std::invalid_argument("Error allocating memory!");
	}

	result = fread(data, 1, count, fh);

	if(result != count) {
		throw std::invalid_argument("Error reading from file!");
	}

	append(data, size);

	//returning file handler pointer to the previous position
	fseek(fh, previous_pos, SEEK_SET);
	
	return 0;
}