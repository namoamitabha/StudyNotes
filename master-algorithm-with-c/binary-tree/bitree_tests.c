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
	EXPECT_EQ(j, *((int *)bitree_data(tree->root->right)));

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

TEST(BiTree, bitree_rem_left)
{
	BiTree *tree = (BiTree *)malloc(sizeof(BiTree));

	bitree_init(tree, destroy);

	int *a = (int *)malloc(sizeof(int));

	*a = 0;
	bitree_ins_left(tree, NULL, a);

	int *b = (int *)malloc(sizeof(int));

	*b = 1;
	bitree_ins_left(tree, bitree_root(tree), b);
	EXPECT_EQ(2, bitree_size(tree));

	bitree_rem_left(tree, bitree_root(tree));
	EXPECT_EQ(1, bitree_size(tree));
	EXPECT_TRUE(NULL == bitree_root(tree)->left);

	bitree_rem_left(tree, NULL);
	EXPECT_EQ(0, bitree_size(tree));
	EXPECT_TRUE(NULL == bitree_root(tree));

	free(tree);
}

TEST(BiTree, bitree_rem_right)
{
	BiTree *tree = (BiTree *)malloc(sizeof(BiTree));

	bitree_init(tree, destroy);

	int *a = (int *)malloc(sizeof(int));

	*a = 10;
	bitree_ins_right(tree, bitree_root(tree), a);

	int *b = (int *)malloc(sizeof(BiTree));

	*b = 11;
	bitree_ins_right(tree, bitree_root(tree), b);
	EXPECT_EQ(2, bitree_size(tree));

	bitree_rem_right(tree, bitree_root(tree));
	EXPECT_EQ(1, bitree_size(tree));
	EXPECT_TRUE(NULL == bitree_root(tree)->right);

	bitree_rem_right(tree, NULL);
	EXPECT_EQ(0, bitree_size(tree));
	EXPECT_TRUE(NULL == bitree_root(tree));

	free(tree);
}

TEST(BiTree, bitree_merge)
{
	int result;
	BiTree *merge = (BiTree *)malloc(sizeof(BiTree));
	BiTree *left = (BiTree *)malloc(sizeof(BiTree));
	BiTree *right = (BiTree *)malloc(sizeof(BiTree));

	bitree_init(merge, destroy);
	bitree_init(left, destroy);
	bitree_init(right, destroy);

	int *a = (int *)malloc(sizeof(int));

	*a = 11;
	bitree_ins_left(left, bitree_root(left), a);
	
	int *b = (int *)malloc(sizeof(int));

	*b = 12;
	bitree_ins_right(right, bitree_root(right), b);

	int *c = (int *)malloc(sizeof(int));

	*c = 10;
	result = bitree_merge(merge, left, right, c);
	EXPECT_EQ(0, result);
	EXPECT_EQ(3, bitree_size(merge));
	EXPECT_TRUE(NULL == bitree_root(left));
	EXPECT_TRUE(NULL == bitree_root(right));
}
