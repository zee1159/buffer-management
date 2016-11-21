#include "Buffer.h"
#include <stdlib.h>


void Buffer::Buffer(const Buffer& buff) {
	if(buff.capacity > 0 )
	{
		data = new char[buff.capacity];

		if(buff.size > 0)
		  std::memcpy (data, buff.data, buff.size);

		if(buff.lastposition >= 0)
			lastposition = buff.lastposition;
	}
	else data_ = 0;

	size = buff.size;
	capacity = buff.capacity;
	
}