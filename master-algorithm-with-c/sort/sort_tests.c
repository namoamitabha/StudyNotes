#include "sort.h"
#include <gtest/gtest.h>
#include <stdlib.h>
#include <time.h>

static void print_array(int *a, int size)
{
	int i;

	for (i = 0; i < size; ++i) {
		printf("%d,", a[i]);
	}
	printf("\n");

}

int compare(const void *key1, const void *key2)
{
	if (*((int *)key1) > *((int *)key2))
		return 1;
	else if (*(int *)key1 == *((int *)key2))
		return 0;

	return -1;
}

TEST(Sort_Insertion, issort)
{
	int size = 100;
	int *data = (int *)malloc(sizeof(int) * size);
	int i;
	int result;

	srand(time(NULL));

	for (i = 0; i < size; ++i) {
		data[i] = rand() % size;
		/* data[i] = 5 - i; */
		/* printf("%d\n", data[i]); */
	}

	result = issort(data, size, sizeof(int), compare);
	EXPECT_EQ(0, result);
	for (i = 0; i < size; ++i) {
		EXPECT_TRUE(data[i] >= data[i - 1]);
		/* printf("%d\n", data[i]); */
	}
	free(data);
}

TEST(Sort_Quick, qksort)
{
	int size = 100;
	int *data = (int *)malloc(sizeof(int) * size);
	int i;
	int result;

	srand(time(NULL));

	for (i = 0; i < size; ++i) {
		data[i] = rand() % size;
		/* data[i] = 5 - i; */
		/* printf("%d\n", data[i]); */
	}

	result = qksort(data, size, sizeof(int), 0, size - 1, compare);
	EXPECT_EQ(0, result);

	for (i = 0; i < size - 1; ++i) {
		/* printf("%d\n", data[i]); */
		EXPECT_TRUE(data[i] <= data[i + 1]);
	}
	/* printf("%d\n", data[i]); */
}

TEST(Sort_Merge, mgsort)
{
	int size = 5;
	int i;
	int result;
	int *data = (int *)malloc(sizeof(int) * size);

	srand(time(NULL));

	for (i = 0; i < size; ++i) {
		data[i] = 5 - i;
	}
	print_array(data, size);

	result = mgsort(data, size, sizeof(int), 0, size -1, compare);
	EXPECT_EQ(0, result);

	for (i = 0; i < size - 1; ++i) {
		EXPECT_TRUE(data[i] <= data[i + 1]);
	}
	print_array(data, size);
}

TEST(Sort_Merge, mgsort_random)
{
	int size = 5;
	int i;
	int result;
	int *data = (int *)malloc(sizeof(int) * size);

	srand(time(NULL));

	for (i = 0; i < size; ++i) {
		data[i] = rand() % size;
	}
	print_array(data, size);

	result = mgsort(data, size, sizeof(int), 0, size -1, compare);
	EXPECT_EQ(0, result);

	for (i = 0; i < size - 1; ++i) {
		EXPECT_TRUE(data[i] <= data[i + 1]);
	}
	print_array(data, size);
}

TEST(Sort_Count, ctsort)
{
	int result;
	int size = 10;
	int k = 200;
	int i;
	int *a = (int *)malloc(sizeof(int) * size);

	for (i = 0; i < size; ++i) {
		a[i] = size - i;
	}

	result = ctsort(a, size, k);
	EXPECT_EQ(0, result);

	for (i = 0; i < (size - 1); ++i) {
		EXPECT_TRUE(a[i] <= a[i + 1]);
	}
}

TEST(Sort_Count, ctsort_random)
{
	int result;
	int size = 10;
	int k = 200;
	int i;
	int *a = (int *)malloc(sizeof(int) * size);

	srand(time(NULL));

	for (i = 0; i < size; ++i) {
		a[i] = rand() % k;
	}

	result = ctsort(a, size, k);
	EXPECT_EQ(0, result);

	for (i = 0; i < (size - 1); ++i) {
		EXPECT_TRUE(a[i] <= a[i + 1]);
	}
}

TEST(Sort_Count, ctsort_equal)
{
	int result;
	int size = 10;
	int k = 9;
	int i;
	int *a = (int *)malloc(sizeof(int) * size);

	srand(time(NULL));

	for (i = 0; i < size; ++i) {
		a[i] = rand() % k;
	}

	result = ctsort(a, size, k);
	EXPECT_EQ(0, result);

	for (i = 0; i < (size - 1); ++i) {
		EXPECT_TRUE(a[i] <= a[i + 1]);
	}
}


TEST(Sort_Radix, rxsort_random)
{
	int result;
	int size = 10;
	int *a = (int *)malloc(sizeof(int) * size);
	int i;
	int p = 3;
	int k = 10;

	srand(time(NULL));

	for (i = 0; i < size; ++i) {
		a[i] = rand() % 1000;
	}
#ifdef DEBUG
	print_array(a, size);
#endif

	result = rxsort(a, size, p, k);
	EXPECT_EQ(0, result);

	for (i = 1; i < size; ++i) {
		EXPECT_TRUE(a[i] >= a[i - 1]);
	}
#ifdef DEBUG
	print_array(a, size);
#endif
}

TEST(Sort_Radix, rxsort)
{
	int result;
	int size = 10;
	int *a = (int *)malloc(sizeof(int) * size);
	int i;
	int p = 2;
	int k = 10;

	srand(time(NULL));

	for (i = 0; i < size; ++i) {
		a[i] = 10 - i;
	}
#ifdef DEBUG
	print_array(a, size);
#endif

	result = rxsort(a, size, p, k);
	EXPECT_EQ(0, result);

	for (i = 1; i < size; ++i) {
		EXPECT_TRUE(a[i] >= a[i - 1]);
	}
#ifdef DEBUG
	print_array(a, size);
#endif
}

