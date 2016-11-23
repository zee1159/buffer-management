#ifndef PREFETCHER
#define PREFETCHER

#include "buffer.h"
#include <cstddef>
#include <cstring>
#include <stdexcept>

class prefetcher
{
public:
	typedef int pageNumber;

	// typedef struct pageHandler {
	// 	pageNumber pageNum;
	// 	char *data;	
	// } pageHandler;

	prefetcher();

	int prefetch(Buffer *const buff, 

	~prefetcher();
	
};

#endif
