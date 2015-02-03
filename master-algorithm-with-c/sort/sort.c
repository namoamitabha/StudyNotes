#include "sort.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* #define DEBUG */

int issort(void *data, int size, int esize,
	   int (*compare)(const void *key1, const void *key2))
{
	int i;
	int j;
	char *a = (char *)data;
	void *key = (char *)malloc(esize);

	if (NULL == key)
		return -1;

	for (i = 1; i < size; ++i) {
		/* key = data[i]; */
		memcpy(key, &a[i * esize], esize);
#ifdef DEBUG
		printf("key=%d\n", *((int *)key));
#endif
		for (j = i - 1; j >= 0; --j) {
			if (compare(&a[j * esize], key) > 0) {
				/* data[j + 1] = *(data + j); */
				memcpy(&a[(j + 1) * esize], &a[j * esize], esize);
			} else {
				/* data[j + 1] = key; */
				memcpy(&a[(j + 1) * esize], key, esize);
				break;
			}
		}
		if (j < 0)
			memcpy(&a[0], key, esize);
	}

	free(key);

	return 0;
}
