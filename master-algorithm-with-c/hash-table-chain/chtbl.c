#include "chtbl.h"
#include <string.h>

int get_key(const CHTbl *htbl, const void *data)
{
	return htbl->h(data) % htbl->buckets;
}

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
		/* list_init(htbl->table + i, destroy); */
		list_init(&htbl->table[i], destroy);
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
	void *tmp = (void *)data;

	if (0 == chtbl_lookup(htbl, &tmp))
		return 1;

	int key = get_key(htbl, data);

	int result = list_ins_next(htbl->table + key, NULL, data);
	if (0 == result)
		++htbl->size;

	return result;
}

int chtbl_lookup(const CHTbl *htbl, void **data)
{
	int key = get_key(htbl, *data);

	ListElmt *current = list_head(htbl->table + key);

	while (NULL != current) {
		if (htbl->match(*data, list_data(current))) {
			*data = list_data(current);
			return 0;
		}
	}

	return -1;
}


int chtbl_remove(CHTbl *htbl, void **data)
{
	int key = get_key(htbl, *data);

	List *list = htbl->table + key;
	ListElmt *current = list_head(list);
	ListElmt *prev = NULL;
	int result;

	while (NULL != current) {
		if (htbl->match(*data, list_data(current))) {
			result = list_rem_next(list, prev, data);
			if (0 == result)
				--htbl->size;
			return result;
		}
		prev = current;
		current = current->next;
	}
	return -1;
}

void chtbl_destroy(CHTbl *htbl)
{
	int i;

	for (i = 0; i < htbl->buckets; ++i) {
		list_destroy(htbl->table + i);
		/* free(list); */
	}

	free(htbl->table);

	memset(htbl, 0, sizeof(CHTbl));
}
