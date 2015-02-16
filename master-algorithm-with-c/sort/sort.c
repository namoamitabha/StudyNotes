#include "sort.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define CDEBUG

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

static int qksort_compare(const void *key1, const void *key2)
{
	if (*(const int *)key1 > *(const int *)key2)
		return 1;
	else if (*(const int *)key1 == *(const int *)key2)
		return 0;
	return 0;
}

static int qksort_get_median_of_three(int i, int k)
{
	int r[3], m;

	srand(time(NULL));

	m = k - i + 1;

	r[0] = rand() % m + i;
	r[1] = rand() % m + i;
	r[2] = rand() % m + i;

	issort(r, 3, sizeof(int), qksort_compare);

#ifdef DEBUG
	printf("i=%d, k=%d, n=%d\n", i, k, r[1]);
#endif

	return r[1];
}

/* Use median of three method to select partition */
static int qksort_partition(void *data, int esize, int i, int k,
			    int (*compare)(const void *key1, const void *key2))
{
	int l, m;
	char *a = (char *)data;

	/* assumre k element as key */
	int n = qksort_get_median_of_three(i , k);

	if (qksort_exchange(&a[n * esize], &a[k * esize], esize) < 0)
		return -1;

	l = i;
	m = k - 1;
	while (l <= m) {
		if (compare(&a[l * esize], &a[k * esize]) >= 0) {
			/* exchange l with m */
			if (qksort_exchange(&a[l * esize], &a[m * esize], esize)
				< 0)
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

	int m = qksort_partition(data, esize, i, k, compare);

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

static void print_array(void *data, int size)
{
	int i;

	for (i = 0; i < size; ++i) {
		printf("%d ", *(((int *)data) + i));
		/* printf("%d", (int)data[i]); */
	}
	printf("\n");
}

static int mgsort_merge(void *data, int esize, int i, int m, int k,
			int (*compare)(const void *key1, const void *key2))
{
	int n	  = m + 1;
	int lsize = m - i + 1;
	int rsize = k - n + 1;
	char *data_cp = (char *)data;

#ifdef DEBUG
	printf("mgsort_merge:i=%d, m=%d, n=%d, k=%d\n", i, m, n, k);
	print_array(data, 5);
#endif

	char *ldata = (char *)malloc(esize * lsize);

	if (NULL == ldata)
		return -1;

	char *rdata = (char *)malloc(esize * rsize);

	if (NULL == rdata) {
		free(ldata);
		return -1;
	}

	int j;

	for (j = 0; j < lsize; ++j)
		memcpy(&ldata[j * esize], &data_cp[(i + j) * esize], esize);

	for (j = 0; j < rsize; ++j)
		memcpy(&rdata[j * esize], &data_cp[(n + j) * esize], esize);

#ifdef DEBUG
	print_array(ldata, lsize);
	print_array(rdata, rsize);
#endif
	int l_i = 0, r_i = 0, index = i;

	while (l_i < lsize && r_i < rsize) {
#ifdef DEBUG
		printf("index=%d, ldata[%d]=%d, rdata[%d]=%d\n",
		       index, l_i, ldata[l_i * esize], r_i, rdata[r_i * esize]);
#endif
		if (compare(&ldata[l_i * esize], &rdata[r_i * esize]) < 0) {
			memcpy(&data_cp[index * esize], &ldata[l_i * esize], esize);
			++l_i;
		} else {
			memcpy(&data_cp[index * esize], &rdata[r_i * esize], esize);
			++r_i;
		}
		++index;
	}

	while (l_i < lsize) {
		memcpy(&data_cp[index * esize], &ldata[l_i * esize], esize);
		++index;
		++l_i;
	}

	while (r_i < rsize) {
		memcpy(&data_cp[index * esize], &rdata[r_i * esize], esize);
		++index;
		++r_i;
	}

#ifdef DEBUG
	print_array(data, 5);
#endif

	free(ldata);
	free(rdata);

	return 0;
}

int mgsort(void *data, int size, int esize, int i, int k,
	   int (*compare)(const void *key1, const void *key2))
{
	if (i >= k)
		return 0;

	int m = (i + k) / 2;

#ifdef DEBUG
	printf("mgsort:i=%d, k=%d, m=%d\n", i, k, m);
#endif

        if (mgsort(data, size, esize, i, m, compare) < 0)
		return -1;

	if (mgsort(data, size, esize, m + 1, k, compare) < 0)
		return -1;

	if (mgsort_merge(data, esize, i, m, k, compare) < 0)
		return -1;

	return 0;
}

int ctsort(int *data, int size, int k)
{
#ifdef DEBUG
	print_array(data, size);
#endif
	int i;
	int *counter = (int *)calloc(k, sizeof(int));

	if (NULL == counter)
		return -1;

	int *temp = (int *)malloc(size * sizeof(int));

	if (NULL == temp) {
		free(counter);
		return -1;
	}

	for (i = 0; i < size; ++i) {
		++counter[data[i]];
	}

	for (i = 1; i < k; ++i)
		counter[i] += counter[i - 1];

	for (i = size - 1; i >= 0; --i) {
		temp[counter[data[i]] - 1] = data[i];
		--counter[data[i]];
	}

	memcpy(data, temp, size * sizeof(int));

#ifdef DEBUG
	print_array(data, size);
#endif

	free(counter);
	free(temp);

	return 0;
}

int rxsort(int *data, int size, int p, int k)
{
	int *counter = (int *)calloc(k, sizeof(int));

	if (NULL == counter)
		return -1;

	int *temp = (int *)malloc(size * sizeof(int));

	if (NULL == temp) {
		free(counter);
		return -1;
	}

	int i;
	int j;
	int index;
	int exp = 1;
	int base = k;

	for (i = 0; i < p; ++i) {
#ifdef DEBUG
		printf("***************");
		printf("i=%d, p=%d, exp=%d, base=%d\n", i, p, exp, base);
		print_array(data, size);
#endif
		
		for (j = 0; j < size; ++j) {
			index = (data[j] / exp) % base;
#ifdef DEBUG
			printf("data=%d, radix=%d; ", data[j], index);
#endif
			++counter[index];
		}
#ifdef DEBUG
		printf("\n");
		print_array(counter, k);
#endif
		for (j = 1; j < k; ++j) {
			counter[j] += counter[j - 1];
		}
#ifdef DEBUG
		print_array(counter, k);
#endif

		for (j = size - 1; j >= 0; --j) {
			index = (data[j] / exp) % base;
			temp[counter[index] - 1] = data[j];
			--counter[index];
		}

		memcpy(data, temp, size * sizeof(int));
#ifdef DEBUG
		print_array(data, size);
#endif

		for (j = 0; j < k; ++j)
			counter[j] = 0;

		exp *= base;
	}

	free(counter);
	free(temp);

	return 0;
}
