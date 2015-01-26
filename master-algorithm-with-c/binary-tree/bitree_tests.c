#include "bitree.h"
#include <gtest/gtest.h>
#include <stdlib.h>

void destroy(void *data)
{
	if (NULL != data)
		free(data);
}

TEST(BiTree, bitree_init)
{
	int result;
	BiTree *tree = (BiTree *)malloc(sizeof(BiTree));

	bitree_init(tree, destroy);
	EXPECT_EQ(0, bitree_size(tree));
	EXPECT_TRUE(NULL == bitree_root(tree));
	EXPECT_TRUE(destroy == tree->destroy);

	free(tree);
}
