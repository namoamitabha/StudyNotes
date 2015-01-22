#include "chtbl.h"
#include <gtest/gtest.h>
#include <stdlib.h>

#define DEBUG

int h(const void *key)
{
	//buckets: 100
	//prime base: 47, 100/47 = 2.13
	int base = 47; // base should a little less than buckets
	return *((int *)key) % base;
}

int match(const void *key1, const void *key2)
{
	if (*((int *)key1) == *((int *)key2))
		return 1;
	return 0;
}

void destroy(void *data)
{
	free(data);
}

TEST(CHTbl, chtbl_init)
{
	int result;

	CHTbl *htbl = (CHTbl *)malloc(sizeof(CHTbl));

	result = chtbl_init(htbl, 10, h, match, destroy);
	EXPECT_EQ(0, result);
	EXPECT_EQ(0, htbl->size);
	EXPECT_EQ(10, htbl->buckets);
	EXPECT_TRUE(h == htbl->h);
	EXPECT_TRUE(match == htbl->match);
	EXPECT_TRUE(destroy == htbl->destroy);
	EXPECT_TRUE(NULL != htbl->table);

	chtbl_destroy(htbl);
	free(htbl);
}

TEST(CHTbl, chtbl_insert)
{
	int result;

	CHTbl *htbl = (CHTbl *)malloc(sizeof(CHTbl));

	chtbl_init(htbl, 100, h, match, destroy);

	int *a = (int *)malloc(sizeof(int));

	*a = 1;
	result = chtbl_insert(htbl, a);
	EXPECT_EQ(0, result);
	EXPECT_EQ(1, chtbl_size(htbl));

	int *b = (int *)malloc(sizeof(int));

	*b = 2;
	result = chtbl_insert(htbl, b);
	EXPECT_EQ(0, result);
	EXPECT_EQ(2, chtbl_size(htbl));

	result = chtbl_insert(htbl, a);
	EXPECT_EQ(1, result);
	EXPECT_EQ(2, chtbl_size(htbl));

	int *data;
	int i;
	for (i = 100; i < 120; ++i) {
		data = (int *)malloc(sizeof(int));
		*data = i;
		result = chtbl_insert(htbl, data);
		EXPECT_EQ(0, result);
		/* printf("%d result: %d chtbl_size:%d\n", i, result, chtbl_size(htbl)); */
	}

	chtbl_destroy(htbl);
	free(htbl);
}

TEST(CHTbl, chtbl_lookup)
{
	int result;
	int *data = (int *)malloc(sizeof(int));

	CHTbl *htbl = (CHTbl *)malloc(sizeof(CHTbl));

	chtbl_init(htbl, 100, h, match, destroy);

	int *a = (int *)malloc(sizeof(int));

	*a = 32;
	chtbl_insert(htbl, a);

	*data = 32;
	result = chtbl_lookup(htbl, (void **)&data);
	EXPECT_EQ(0, result);
	EXPECT_TRUE(a == data);

	*data = 33;
	result = chtbl_lookup(htbl, (void **)&data);
	EXPECT_EQ(-1, result);

	int *b = (int *)malloc(sizeof(int));

	*b = 77;
	chtbl_insert(htbl, b);

	*data = 77;
	result = chtbl_lookup(htbl, (void **)&data);
	EXPECT_EQ(0, result);
	EXPECT_TRUE(b == data);

	*data = 101;
	result = chtbl_lookup(htbl, (void **)&data);
	EXPECT_EQ(-1, result);

	chtbl_destroy(htbl);
	free(htbl);
}

TEST(CHTbl, chtbl_remove)
{
	int result;
	int *data = (int *)malloc(sizeof(int));
	int i;

	CHTbl *htbl = (CHTbl *)malloc(sizeof(CHTbl));

	chtbl_init(htbl, 100, h, match, destroy);

	int *a;

	for (i = 100; i < 110; ++i) {
		a = (int *)malloc(sizeof(int));
		*a = i;
		result = chtbl_insert(htbl, a);
		EXPECT_EQ(0, result);
	}

	EXPECT_EQ(10, chtbl_size(htbl));

	*data = 100;
	result = chtbl_remove(htbl, (void **)&data);
	EXPECT_EQ(0, result);
	EXPECT_EQ(9, chtbl_size(htbl));

	*data = 101;
	result = chtbl_remove(htbl, (void **)&data);
	EXPECT_EQ(0, result);
	EXPECT_EQ(8, chtbl_size(htbl));

	*data = 99;
	result = chtbl_remove(htbl, (void **)&data);
	EXPECT_EQ(-1, result);

	free(data);
	chtbl_destroy(htbl);
	free(htbl);
}

TEST(CHTbl, chtbl_destroy)
{
	CHTbl *htbl = (CHTbl *)malloc(sizeof(CHTbl));

	chtbl_init(htbl, 100, h, match, destroy);

	int i;
	int result;
	int *data;

	for (i = 200; i < 220; ++i) {
		data = (int *)malloc(sizeof(int));
		*data = i;
		result = chtbl_insert(htbl, data);
		/* printf("%d chtbl_insert result:%d\n", i, result); */
	}

	EXPECT_EQ(20, chtbl_size(htbl));

	chtbl_destroy(htbl);
	free(htbl);
}

TEST(CHTbl, performance)
{
	CHTbl *htbl = (CHTbl *)malloc(sizeof(CHTbl));

	chtbl_init(htbl, 100, h, match, destroy);

	int i;
	int result;
	int *data;

	for (i = 200; i < 250; ++i) {
		data = (int *)malloc(sizeof(int));
		*data = i;
		result = chtbl_insert(htbl, data);
		printf("%d chtbl_insert result:%d\n", i, result);
	}

	EXPECT_EQ(50, chtbl_size(htbl));

	chtbl_destroy(htbl);
	free(htbl);
}
