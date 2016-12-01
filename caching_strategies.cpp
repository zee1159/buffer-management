// ***-------------------------***-------------------------*** //
#include "buffer.h"
#include <stdlib.h>
#include "caching_mechanisms.h"
// ***-------------------------***-------------------------*** //

/*

Assuming the following kind of structures
to define the buffer class and the page
class : -

struct BufferPool
{
  int numPages; // the num of pages currently
                   residing in the cache.

  void *data; // represents the array of pages,
                 which represents the data inside
                 the cache.

  size_t capacity; // the total capacity of the cache
}

struct Page
{
  char *pagedata;
  int pagenum; default value = -1 => empty_page
  int dirtybit; default value = -1 => not_dirty
  int ranking; default value = INT_MAX
  int readcount; default value = 0
}

 Note that the default values are only assumptions
 and just a way of representing the data when we will
 first initialize the buffer.

 INT_MAX = 1000 ; basically need some large value.
                  this will be used later to define
                  'ranking' and thereafter guide our
                  replacement policy, as we shall see.

*/

// ***-------------------------***-------------------------*** //

// ***-------------------------***-------------------------*** //


/*
 *    LEAST RECENTLY USED -  Cache Replacement Policy
 *
 * Definition - replaces the least recently used page
 *
 * Paramters - (i) a buffer handler, defined by the struct
 *             given in the description above, which
 *             represents our cache here.
 *
 *             (ii) the fresh page which needs to be added.
 *             The page has the form defined in the struct
 *             above
 *
 * Description - Basically we read in the data stored inside
 *               the cache/buffer into a data/pages pointer.
 *
 *               Then we iterate over each of these pages to
 *               search for the page with the minimum rank.
 *
 *               If the minimum ranking page has its dirty bit
 *               set, i.e., it has been updated after it was
 *               read in from the backing store to the cache,
 *               Then, we have to write the data back to the
 *               main storage to persist the changes.
 *
 *               Then we replace the data at this index, within
 *               our data array, with our fresh data.
 *
 *               The ranking of a newly used page is updated to
 *               be INT_MAX. To represent the most recently used
 *               page.
 *
 *               The rankings of all the other pages is updated
 *               thereafter, wherein we
 *               reduce the ranking of each by subtracting 1 from
 *               their existing ranking.
 *
 *               The last two things are updated in a seperate
 *               function called decreaseRankingForPages(...)
 */


void lru (Page *pages, const void *data, int numPages)
{
  int eviction_index = 0;
  int minimum_rank = INT_MAX;

  int i;
  //search for min rank.
  for (i = 0; i<numPages; i++)
  {
    if (pages[i].ranking < minimum_rank)
    {
      minimum_rank = pages[i].ranking;
      eviction_index = i;
    }
  }

  pages[eviction_index].pagedata = data;
  pages[eviction_index].pagenum = 1;

  int i;
  for (i = 0; i<numPages; i++)
  {
      if (i != evictedpage_index || pages[i].pagenum != -1)
      {
          pages[i].ranking = pages[i].ranking - 1;
      }
      if (i == evictedpage_pageindex)
      {
          pages[i].ranking = INT_MAX;
      }
  }
}
// ***-------------------------***-------------------------*** //
