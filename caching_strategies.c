/*

Assuming the following structures to
define the buffer class and the page
class : -

struct BufferPool
{
  int numPages;
  void *data;
  size_t capacity;
}

struct Page
{
  char *pagedata;
  int pagenum; default value = -1 => empty_page
  int dirtybit; default value = -1 => not_dirty
  int ranking; default value = INT_MAX
  int readcount; default value = 0
}

*/

void lru (BufferPool *const bm, Page *freshpage)
{
  Page *pages = (page *)bm->data;
  int i;
  int eviction_index = 0;
  int minimum_rank = INT_MAX;

  //search for min rank.
  for (i = 0; i<bm->numPages; i++)
  {
    if (pages[i].ranking < minimum_rank)
    {
      minimum_rank = pages[i].ranking;
      eviction_index = i;
    }
  }

  if(pages[eviction_index].dirtybit == DIRTY_FLAG)
  {
    // Write block to backing store
    //write_function_prototype(bm, &pages[eviction_index]);
  }
  pages[eviction_index].pagedata = freshpage->pagedata;
  pages[eviction_index].pagenum = freshpage->pagenum;
  pages[eviction_index].dirtybit = freshpage->dirtybit;

  decreaseRankingForPages(bm, eviction_index);
}

void decreaseRankingForPages(BufferPool *const bm, int pageindex)
{
  Page *pages = (Page *) bm->data;
  int i;
  for (i = 0; i<bm->numPages; i++)
  {
    if (i != pageindex || pages[i].pagenum != -1)
    {
      pages[i].ranking = pages[i].ranking - 1;
    }
    if (i == pageindex)
    {
      pages[i].ranking = INT_MAX;
    }
  }
}