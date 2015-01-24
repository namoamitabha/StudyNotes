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

	ohtbl_destroy(htbl);
	free(htbl);
}

TEST(OHTbl, ohtbl_insert)
{
	int result;
	OHTbl *htbl = (OHTbl *)malloc(sizeof(OHTbl));
}
