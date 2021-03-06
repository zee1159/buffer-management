#ifndef BUFFER
#define BUFFER

#include <cstddef>
#include <cstring>
#include <stdexcept>
#include "caching_strategies.h"

class Buffer
{

public:

	Buffer();

	//Buffer(size_t capacity, ReplacementStrategy strat);
	Buffer(size_t capacity, size_t pagesize);	// Buffer inititalization function

	void append(const void *data, size_t size);

	void bufferManager(const void *data);

	bool isFull();

	//~Buffer();

	typedef struct Page
	{
	  char *pagedata;	// data contained in page
	  int pagenum; 		// default value = -1 => empty_page
	  // int dirtybit; 	// default value = -1 => not_dirty
	  int ranking; 		// default value = INT_MAX
	  // int readcount; 	// default value = 0
	} Page;

	typedef enum ReplacementStrategy {
	  RS_FIFO = 0,
	  RS_LRU = 1,
	  RS_LFU = 2,
	} ReplacementStrategy;


private:
	//variables
	int numPages;		// Total number of pages in cache
  	//void *data_;			// points to the pages in cache
  	size_t capacity_;	// total size of the buffer
  	size_t pagesize_;
  	
  	int lastPageUpdate = 0; 	// points to last updated page
  	int lineCount = 0;	// points to count of cache lines
  	
  	ReplacementStrategy strategyId;
  	Page *pages;

  	caching_strategies cache_manager;

  	

};

#endif
