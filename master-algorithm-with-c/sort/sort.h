#ifndef SORT_H
#define SORT_H

/* insertion sort */
int issort(void *data, int size, int esize,
	   int (*compare)(const void *key1, const void *key2));

/* quick sort */
int qksort(void *data, int size, int esize, int i, int k,
	   int (*compare)(const void *key1, const void *key2));

/* merge sort */
int mgsort(void *data, int size, int esize, int i, int k,
	   int (*compare)(const void *key1, const void *key2));

/* count sort */
int ctsort(int *data, int size, int k);

/* radix sort */
int rxsort(int *data, int size, int p, int k);

/* binary search */
int bisearch(void *sorted, void *target, int size, int esize,
	     int (*compare)(const void *key1, const void *key2));

#endif
