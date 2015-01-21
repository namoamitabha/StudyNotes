#include "chtbl.h"

int chtbl_init(CHTbl *htbl, int buckets,
	       int (*h)(const void *key),
	       int (*match)(const void *key1, const void *key2),
	       void (*destroy)(void *data))
{
	htbl->table = (List *)malloc(sizeof(List) * buckets);
	if (NULL == htbl->table)
		return -1;

	htbl->buckets = buckets;
	htbl->size = 0;
	htbl->h = h;
	htbl->match = match;
	htbl->destroy = destroy;

	return 0;
}
