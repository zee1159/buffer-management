#include "Buffer.h"
#include <stdlib.h>


void Buffer::Buffer(size_t capacity, size_t pagesize, ReplacementStrategy strat) {

	if(capacity > 0 )
	{
		capacity_ = capacity; 
		pagesize_ = pagesize;

		numPages = (capacity / pagesize);
		data = new char[capacity_];

		Page *pages = malloc(sizeof(Page) * numPages);
	}
}

// void Buffer::Buffer(const Buffer& buff) {
// 	if(buff.capacity > 0 )
// 	{
// 		data = new char[buff.capacity];

// 		if(buff.size > 0)
// 		  std::memcpy (data, buff.data, buff.size);

// 		// if(buff.lastposition >= 0)
// 		// 	lastposition = buff.lastposition;
// 	}
// 	else data_ = 0;

// 	size = buff.size;
// 	capacity = buff.capacity;
// 	strate


// }

void Buffer::append()