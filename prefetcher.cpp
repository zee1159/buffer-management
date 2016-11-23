#include <prefetcher.h>
#include <stdlib.h>

inline int prefetcher::prefetch(Buffer *const buff, FILE *fh, size_t size, size_t count){
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

	//returning file handler pointer to the previous position
	fseek(fh, previous_pos, SEEK_SET);

	/*------------------------*/
	/*----< PREVIOUS CODE>----*/
	/*------------------------*/

	//buffer is empty return error code (-1)
	if(buff -> data == NULL) {
		return -1;
	}

	// ------------- Get last read page --------------- //

	// For which need to get the data inside the buffer
	Page *pages = (page *)buff -> data

	// index of last inserted page inside this pages array
	// = last position, read that,
	lastposition = buff -> lastposition;

	// get the data at this index
	lastPageData = pages[lastposition] -> pagedata;

	// compare if void * data = lastpage data
	checkData = (data == lastPageData) ? TRUE : FALSE;

	// braches according to the checkdata result

	// if checkdata = true,
	// then fetch the next data from the backing store.
	if(checkData){

		// check buffer capacity
		if (buff.checkCapacity()){

			// fetch next data from the backing store,
	 		// which we will store in newdata
			buff.append(newDataa)
		}
		else{

			// call cache manager
			cache_manager cm;

			cm.perfromReplacement(buff, &newData)

		}
	}
	else{

		// check buffer capacity
		if (buff.checkCapacity()){

			// fetch next data from the backing store,
	 		// which we will store in newdata
			buff.append(newDataa)
		}
		else{

			// call cache manager
			cache_manager cm;

			cm.perfromReplacement(buff, &newData)

		}
	}
	
}