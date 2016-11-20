#ifndef BUFFER
#define BUFFER

#include <cstddef>
#include <cstring>
#include <stdexcept>

class Buffer
{
public:
	Buffer();
	~Buffer();
	

	//variables
	int numPages;
  	void *data;
  	size_t capacity;

  	typedef struct Page
	{
	  char *pagedata;
	  int pagenum; //default value = -1 => empty_page
	  int dirtybit; //default value = -1 => not_dirty
	  int ranking; //default value = INT_MAX
	  int readcount; //default value = 0
	} Page;
};

#endif
