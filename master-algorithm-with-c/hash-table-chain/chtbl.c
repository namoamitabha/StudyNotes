#include "chtbl.h"

int chtbl_init(CHTbl *htbl, int buckets,
	       int (*h)(const void *key),
	       int (*match)(const void *key1, const void *key2),
	       void (*destroy)(void *data))
{
	htbl->table = (List *)malloc(sizeof(List) * buckets);
	if (NULL == htbl->table)
		return -1;
	int i;

	for (i = 0; i < buckets; ++i) {
		list_init(htbl->table + i, destroy);
	}

	htbl->buckets = buckets;
	htbl->size = 0;
	htbl->h = h;
	htbl->match = match;
	htbl->destroy = destroy;

	return 0;
}

int chtbl_insert(CHTbl *htbl, const void *data)
{
	int key = htbl->h(data);

	int result = list_ins_next(htbl->table + key, NULL, data);
	if (-1 == result)
		return result;

	++htbl->size;

	return 0;
}

int chtbl_lookup(const CHTbl *htbl, void **data)
{
	int key = htbl->h(*data);
	ListElmt *current = (htbl->table + key)->head;
	while (NULL != current) {
		if (htbl->match(*data, list_data(current))) {
			*data = list_data(current);
			return 0;
		}
	}

	return -1;
}
