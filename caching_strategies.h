#ifndef CACHING_STRATEGIES
#define CACHING_STRATEGIES

class caching_strategies
{
	public:
		caching_strategies();
	  	void lru(Buffer::Page *pages, const void *data, int numPages);
};

#endif
