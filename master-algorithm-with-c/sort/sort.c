#include "sort.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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
		memcpy(key, &a[i * esize], esize);
#ifdef DEBUG
		printf("key=%d\n", *((int *)key));
#endif
		j = i - 1;
		while (j >= 0 && compare(&a[j * esize], key) > 0) {
			memcpy(&a[(j + 1) * esize], &a[j * esize], esize);
			--j;
		}
		memcpy(&a[(j + 1) * esize], key, esize);
	}

	free(key);

	return 0;
}

static int qksort_exchange(void *item1, void *item2, int esize)
{
	char *tmp = (char *)malloc(esize);

	if (NULL == tmp)
		return -1;

	memcpy(tmp, item1, esize);
	memcpy(item1, item2, esize);
	memcpy(item2, tmp, esize);

	free(tmp);

	return 0;
}
static int qksort_get_random_median(int i, int k)
{
	int a, b, c, r, n;

	srand(time(NULL));

	r = k - i;
	a = rand() % r;
	b = rand() % r;
	c = rand() % r;

	n = (b + c + a) / 3 + i;
	printf("i=%d, k=%d, n=%d\n", i, k, n);

	return n;
}
static int qksort_partition(void *data, int size, int esize, int i, int k,
			    int (*compare)(const void *key1, const void *key2))
{
	int l, m;
	char *a = (char *)data;

	/* assumre k element as key */
	int n = qksort_get_random_median(i , k);

	if (qksort_exchange(&a[n * esize], &a[k * esize], esize) < 0)
		return -1;

	l = i;
	m = k - 1;
	while (l <= m) {
		if (compare(&a[l * esize], &a[k * esize]) >= 0) {
			/* exchange l with m */
			if (qksort_exchange(&a[l * esize], &a[m * esize], esize) < 0)
				return -1;
			/* decrease m */
			--m;
		} else {
			/* increase l */
			++l;
		}
	}

	/* exchange l with k */
	if (qksort_exchange(&a[l * esize], &a[k * esize], esize) < 0)
		return -1;

	return l;
}

int qksort(void *data, int size, int esize, int i, int k,
	   int (*compare)(const void *key1, const void *key2))
{
#ifdef DEBUG
	printf("********i=%d, k=%d\n", i, k);
#endif
	if (i >= k)
		return 0;

	int m = qksort_partition(data, size, esize, i, k, compare);

	if (m < 0)
		return -1;

#ifdef DEBUG
	printf("m=%d\n", m);
#endif

	/* qksort i to m */
	if (qksort(data, size, esize, i, m - 1, compare) < 0)
		return -1;
	/* qksort m + 2 to k */
	if (qksort(data, size, esize, m + 1, k, compare) < 0)
		return -1;

	return 0;
}
