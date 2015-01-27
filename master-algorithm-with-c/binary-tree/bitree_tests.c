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
	BiTree *tree = (BiTree *)malloc(sizeof(BiTree));

	bitree_init(tree, destroy);
	EXPECT_EQ(0, bitree_size(tree));
	EXPECT_TRUE(NULL == bitree_root(tree));
	EXPECT_TRUE(destroy == tree->destroy);

	free(tree);
}

TEST(BiTree, bitree_ins_left)
{
	int result;
	BiTree *tree = (BiTree *)malloc(sizeof(BiTree));

	bitree_init(tree, NULL);

	int i = 0;
	result = bitree_ins_left(tree, NULL, &i);
	EXPECT_EQ(0, result);
	EXPECT_EQ(1, bitree_size(tree));
	EXPECT_TRUE(NULL != bitree_root(tree));
	EXPECT_EQ(i, *((int *)bitree_data(tree->root)));

	int j = 1;
	result = bitree_ins_left(tree, NULL, &j);
	EXPECT_EQ(-1, result);

	result = bitree_ins_left(tree, bitree_root(tree), &j);
	EXPECT_EQ(0, result);
	EXPECT_EQ(2, bitree_size(tree));
	EXPECT_EQ(1, *((int *)(bitree_left(tree->root)->data)));

	int k = 2;
	result = bitree_ins_left(tree, bitree_root(tree), &k);
	EXPECT_EQ(-1, result);

	free(tree);
}

TEST(BiTree, bitree_ins_right)
{
	int result;
	BiTree *tree = (BiTree *)malloc(sizeof(BiTree));

	bitree_init(tree, NULL);

	int i = 0;

	result = bitree_ins_right(tree, bitree_root(tree), &i);
	EXPECT_EQ(0, result);
	EXPECT_EQ(1, bitree_size(tree));
	EXPECT_EQ(i, *((int *)bitree_data(tree->root)));

	int j = 1;

	result = bitree_ins_right(tree, NULL, &j);
	EXPECT_EQ(-1, result);

	result = bitree_ins_right(tree, bitree_root(tree), &j);
	EXPECT_EQ(0, result);
	EXPECT_EQ(2, bitree_size(tree));
	EXPECT_EQ(j, *((int *)bitree_data(tree->root->left)));

	int k = 2;

	result = bitree_ins_right(tree, bitree_root(tree), &k);
	EXPECT_EQ(-1, result);

	free(tree);
}

TEST(BiTree, bitree_destroy)
{
	BiTree *tree = (BiTree *)malloc(sizeof(BiTree));

	bitree_init(tree, destroy);

	int i;
	int *a;
	int result;

	a = (int *)malloc(sizeof(int));
	result = bitree_ins_left(tree, bitree_root(tree), a);
	EXPECT_EQ(0, result);

	a = (int *)malloc(sizeof(int));
	result = bitree_ins_right(tree, bitree_root(tree), a);
	EXPECT_EQ(0, result);

	bitree_destroy(tree);

	free(tree);
}
