#include "ohtbl.h"
#include <gtest/gtest.h>
#include <stdlib.h>

static const int positions = 100;

int h1(const void *key)
{
	return 0;
}

int h2(const void *key)
{
	return 0;
}

int match(const void *key1, const void *key2)
{
	return 0;
}

void destroy(void *data)
{
	free(data);
}

TEST(OHTbl, ohtbl_init)
{
	int result;
	OHTbl *htbl = (OHTbl *)malloc(sizeof(OHTbl));

	result = ohtbl_init(htbl, positions, h1, h2, match, destroy);
	EXPECT_EQ(0, result);
	EXPECT_TRUE(h1 == htbl->h1);
	EXPECT_TRUE(h2 == htbl->h2);
	EXPECT_TRUE(match == htbl->match);
	EXPECT_TRUE(destroy == htbl->destroy);

	EXPECT_EQ(0, ohtbl_size(htbl));
	EXPECT_EQ(positions, htbl->positions);

	/* ohtbl_destroy(htbl); */
	free(htbl);
}
