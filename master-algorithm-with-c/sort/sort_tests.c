#include "sort.h"
#include <gtest/gtest.h>
#include <stdlib.h>
#include <time.h>

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
