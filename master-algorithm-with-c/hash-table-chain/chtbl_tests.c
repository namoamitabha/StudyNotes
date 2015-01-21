#include "chtbl.h"
#include <gtest/gtest.h>
#include <stdlib.h>

int h(const void *key)
{
	return 0;
}

int match(const void *key1, const void *key2)
{
	return 0;
}

void destroy(void *data)
{

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

	free(htbl);
}
