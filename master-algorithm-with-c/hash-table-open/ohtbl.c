#include "ohtbl.h"
#include <string.h>

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

	htbl->table = (void **)malloc(sizeof(void *) * htbl->positions);
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
