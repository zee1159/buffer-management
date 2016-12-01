#include "Buffer.h"
#include "caching_strategies.h"
#include <stdlib.h>
#include <limits.h>


//void Buffer::Buffer(size_t capacity, size_t pagesize, ReplacementStrategy strat) {
Buffer::Buffer(size_t capacity, size_t pagesize) {

	if(capacity > 0 )
	{
		capacity_ = capacity; 
		pagesize_ = pagesize;

		//stratId = strat;
		//stratId = 0;

		numPages = (capacity_ / pagesize_);
		//data = new char[capacity_];

		*pages = malloc(sizeof(pagesize_) * numPages);

		for (int i = 0; i < numPages; i++)
		{
			pages[i].pagedata = NULL;
			pages[i].pagenum = -1;	//empty page
			// pages[i].dirtybit = -1;	//dirty_unflag
			pages[i].ranking = INT_MAX;
			// pages[i].readcount = 0;
		}
	}
	else {
		throw std::invalid_argument("Error invalid buffer size!");
	}
}

void Buffer::append(const void *data, size_t size) {

	/* Implement data size check */
	//if(size > )
	if (!isFull()) {
		for (int i = 0; i < numPages; i++)
		{
			if(pages[i].pagenum == -1) {
				pages[i].data = data;
				pages[i].pagenum = 1;
				lastPageUpdate = i;
			}
		}
	}
	else {
		bufferManager(data);
	}

}

void Buffer::bufferManager(const void *data) {
	lru(*pages, data, numPages);
}

bool Buffer::isFull() {
	if (lineCount < numPages)
	{
		return false;	
	}
	return true;
}

// void Buffer::~Buffer() {
// 	delete[] data
// }