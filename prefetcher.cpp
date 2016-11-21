#include <prefetcher.h>

inline int prefetcher::prefetch(Buffer *const buff, const void* data){
	int check, lastposition;
	char *lastPageData;
	bool checkData;
	char *newData;

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