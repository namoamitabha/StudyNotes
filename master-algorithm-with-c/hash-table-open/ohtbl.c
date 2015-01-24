#include "ohtbl.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define DEBUG

int ohtbl_init(OHTbl *htbl, int positions,
	       int (*h1)(const void *key),
	       int (*h2)(const void *key),
	       int (*match)(const void *key1, const void *key2),
	       void (*destroy)(void *data))
{
	htbl->positions = positions;

	htbl->h1 = h1;
	htbl->h2 = h2;
	htbl->match = match;
	htbl->destroy = destroy;
	htbl->size = 0;
	htbl->vacated = malloc(sizeof(void *));
	if (NULL == htbl->vacated)
		return -1;

	htbl->table = (void **)malloc(sizeof(void *) * htbl->positions);
	if (NULL == htbl->table)
		return -1;

	int i;

	for (i = 0; i < htbl->positions; ++i) {
		*(htbl->table + i) = NULL;
	}

	return 0;
}

void ohtbl_destroy(OHTbl *htbl)
{
	int i;

	for (i = 0; i < htbl->positions; ++i) {
		if (NULL != htbl->destroy)
			htbl->destroy(*(htbl->table + i));
	}

	free(htbl->table);
	memset(htbl, 0, sizeof(OHTbl));
}

int get_key(const OHTbl *htbl, const void *data, int i)
{
	return (htbl->h1(data) + i * htbl->h2(data)) % htbl->positions;
}

int ohtbl_insert(OHTbl *htbl, const void *data)
{
	int i;
	int key;

	for (i = 0; i < htbl->positions; ++i) {
		key = get_key(htbl, data, i);
#ifdef DEBUG
		printf("i=%d, key=%d\n", i, key);
#endif

		if (NULL == htbl->table[key] ||
		    htbl->vacated == htbl->table[key]) {
			htbl->table[key] = (void *)data;
			++htbl->size;
			return 0;
		}
	}

	return -1;
}

int ohtbl_lookup(const OHTbl *htbl, void **data)
{
	int i;
	int key;

	for (i = 0; i < htbl->positions; ++i) {
		key = get_key(htbl, *data, i);
		if (NULL == htbl->table[key])
			return -1;

		if (htbl->vacated == htbl->table[key])
			continue;

		if (htbl->match(htbl->table[key], *data)) {
			*data = htbl->table[key];
			return 0;
		}
	}

	return -1;
}
