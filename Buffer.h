#ifndef BUFFER
#define BUFFER

#include <cstddef>
#include <cstring>
#include <stdexcept>

class Buffer
{
public:
	Buffer(const Buffer& buff);	// Buffer inititalization function

	~Buffer();
	

	//variables
	int numPages;		// Total number of pages in cache
  	void *data;			// points to the pages in cache
  	size_t capacity;	// total size of the buffer
  	size_t size;
  	int lastposition; 	// points to last updated page
  	ReplacementStrategy strategyIdß;

  	typedef struct Page
	{
	  char *pagedata;	// data contained in page
	  int pagenum; 		// default value = -1 => empty_page
	  int dirtybit; 	// default value = -1 => not_dirty
	  int ranking; 		// default value = INT_MAX
	  int readcount; 	// default value = 0
	} Page;

	typedef enum ReplacementStrategy {
	  RS_FIFO = 0,
	  RS_LRU = 1,
	  RS_LFU = 2,
	} ReplacementStrategy;
};

#endif
