#include "ohtbl.h"
#include <gtest/gtest.h>
#include <stdlib.h>

static const int POSITIONS = 100;

int h1(const void *key)
{
	return *((int *)key) % POSITIONS;
}

int h2(const void *key)
{
	return 1 + *((int *)key) % (POSITIONS - 2);
}

int match(const void *key1, const void *key2)
{
	if (*((int *)key1) == *((int *)key2))
		return 1;

	return 0;
}

void destroy(void *data)
{
	if (NULL != data)
		free(data);
}

void print_ohtbl(OHTbl *htbl)
{
	int i;
	for (i = 0; i < POSITIONS; ++i) {
		if (NULL == htbl->table[i])
			printf("%d:NULL\n", i);
		else if (htbl->vacated == htbl->table[i])
			printf("%d:removed\n", i);
		else
			printf("%d:%d\n", i, *((int *)htbl->table[i]));
	}
}

TEST(OHTbl, ohtbl_init)
{
	int result;
	OHTbl *htbl = (OHTbl *)malloc(sizeof(OHTbl));

	result = ohtbl_init(htbl, POSITIONS, h1, h2, match, destroy);
	EXPECT_EQ(0, result);
	EXPECT_TRUE(h1 == htbl->h1);
	EXPECT_TRUE(h2 == htbl->h2);
	EXPECT_TRUE(match == htbl->match);
	EXPECT_TRUE(destroy == htbl->destroy);

	EXPECT_EQ(0, ohtbl_size(htbl));
	EXPECT_EQ(POSITIONS, htbl->positions);
	EXPECT_FALSE(NULL == htbl->vacated);

	ohtbl_destroy(htbl);
	free(htbl);
}

TEST(OHTbl, ohtbl_insert)
{
	int result;
	OHTbl *htbl = (OHTbl *)malloc(sizeof(OHTbl));

	ohtbl_init(htbl, POSITIONS, h1, h2, match, destroy);

	int *a = (int *)malloc(sizeof(int));

	*a = 0;
	result = ohtbl_insert(htbl, a);
	EXPECT_EQ(0, result);
	EXPECT_EQ(1, ohtbl_size(htbl));

	int i;

	for (i = 1; i < 99; ++i) {
		a = (int *)malloc(sizeof(int));
		*a = i;
		result = ohtbl_insert(htbl, a);
		EXPECT_EQ(0, result);
		EXPECT_EQ(i + 1, ohtbl_size(htbl));
	}

	*a = 0;
	result = ohtbl_insert(htbl, a);
	EXPECT_EQ(1, result);

	int *b = (int *)malloc(sizeof(int));

	*b = 101;
	result = ohtbl_insert(htbl, b);
	EXPECT_EQ(-1, result);
	
	ohtbl_destroy(htbl);
	free(htbl);
}

TEST(OHTbl, ohtbl_lookup)
{
	int result;
	int i;
	int *a;

	OHTbl *htbl = (OHTbl *)malloc(sizeof(OHTbl));

	ohtbl_init(htbl, POSITIONS, h1, h2, match, destroy);

	for (i = 0; i < 50; ++i) {
		a = (int *)malloc(sizeof(int));
		*a = i;
		result = ohtbl_insert(htbl, a);
		EXPECT_EQ(0, result);
	}

	int j = 0;
	int *b = &j;

	result = ohtbl_lookup(htbl, (void **)&b);
	EXPECT_EQ(0, result);

	j = 51;
	b = &j;
	result = ohtbl_lookup(htbl, (void **)&b);
	EXPECT_EQ(-1, result);

	ohtbl_destroy(htbl);
	free(htbl);
}

TEST(OHTbl, ohtbl_remove)
{
	int result;
	int i;
	int *a;
	OHTbl *htbl = (OHTbl *)malloc(sizeof(OHTbl));

	ohtbl_init(htbl, POSITIONS, h1, h2, match, destroy);

	a = (int *)malloc(sizeof(int));
	*a = 0;
	ohtbl_insert(htbl, a);
	
	int j = 0;
	void *b = &j;
	result = ohtbl_lookup(htbl, &b);
	EXPECT_EQ(0, result);

	b = &j;
	result = ohtbl_remove(htbl, &b);
	EXPECT_EQ(0, result);
	EXPECT_EQ(0, ohtbl_size(htbl));
	EXPECT_TRUE(a == b);

	for (i = 100; i < POSITIONS * 2; ++i) {
		a = (int *)malloc(sizeof(int));
		*a = i;
		result = ohtbl_insert(htbl, a);
		EXPECT_EQ(0, result);
	}
	EXPECT_EQ(POSITIONS, ohtbl_size(htbl));

	a = (int *)malloc(sizeof(int));
	*a = 500;
	result = ohtbl_insert(htbl, a);
	EXPECT_EQ(-1, result);

	j = 100;
	b = &j;
	result = ohtbl_lookup(htbl, &b);
	EXPECT_EQ(0, result);
	EXPECT_EQ(j, *((int *)b));
	EXPECT_FALSE(&j == b);

	b = &j;
	result = ohtbl_remove(htbl, &b);
	EXPECT_EQ(0, result);
	EXPECT_EQ(j, *((int *)b));
	EXPECT_FALSE(&j == b);
	EXPECT_EQ(POSITIONS - 1, ohtbl_size(htbl));
	free(b);

	int l = 500;
	b = &l;
	result = ohtbl_remove(htbl, &b);
	EXPECT_EQ(-1, result);

	int k = 100;
	b = &k;
	result = ohtbl_lookup(htbl, &b);
	EXPECT_EQ(-1, result);

	int *c = (int *)malloc(sizeof(int));
	*c = 200;
	result = ohtbl_insert(htbl, c);
	EXPECT_EQ(0, result);

	/* print_ohtbl(htbl); */

	j = 200;
	b = &j;
	result = ohtbl_lookup(htbl, &b);
	EXPECT_EQ(0, result);
	EXPECT_EQ(j, *((int *)b));

	ohtbl_destroy(htbl);
	free(htbl);
}
