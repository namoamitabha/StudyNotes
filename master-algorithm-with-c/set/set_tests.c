#include "set.h"
#include <gtest/gtest.h>
#include <stdlib.h>

void destroy(void *data)
{
	if (NULL != data)
		free(data);
}

int match(const void *key1, const void *key2)
{
	if (*((int *)key1) == *((int *)key2))
		return 1;
	else
		return 0;
}

TEST(Set, set_init)
{
	Set *set = (Set *)malloc(sizeof(Set));

	set_init(set, match, destroy);
	EXPECT_TRUE(match == set->match);
	EXPECT_TRUE(destroy == set->destroy);

	set_destroy(set);
	free(set);
}

TEST(Set, set_is_member)
{
	int result = 0;
	Set *set = (Set *)malloc(sizeof(Set));

	set_init(set, match, destroy);

	int *a = (int *)malloc(sizeof(int));

	*a = 0;
	list_ins_next(set, NULL, a);

	int *b = (int *)malloc(sizeof(int));

	*b = 1;
	list_ins_next(set, NULL, b);

	result = set_is_member(set, b);
	EXPECT_EQ(1, result);

	int *c = (int *)malloc(sizeof(int));

	*c = 3;
	result = set_is_member(set, c);
	EXPECT_EQ(0, result);

	set_destroy(set);
	free(set);
}

TEST(Set, set_insert)
{
	int result = 0;
	Set *set = (Set *)malloc(sizeof(Set));

	set_init(set, match, destroy);

	int *a = (int *)malloc(sizeof(int));

	*a = 1;
	result = set_insert(set, a);
	EXPECT_EQ(0, result);

	result = set_insert(set, a);
	EXPECT_EQ(-1, result);

	set_destroy(set);
	free(set);
}

TEST(Set, set_remove)
{
	int result;
	Set *set = (Set *)malloc(sizeof(Set));

	set_init(set, match, destroy);

	int *a = (int *)malloc(sizeof(int));

	*a = 1;
	EXPECT_EQ(0, set_insert(set, a));

	int *b = (int *)malloc(sizeof(int));

	*b = 1;
	result = set_remove(set, (void **)&b);
	EXPECT_EQ(0, result);
	EXPECT_TRUE(a == b);
	result = set_is_member(set, a);
	EXPECT_EQ(0, result);

	EXPECT_EQ(0, set_insert(set, a));

	int *c = (int *)malloc(sizeof(int));

	*c = 2;
	result = set_remove(set, (void **)&c);
	EXPECT_EQ(-1, result);
	EXPECT_FALSE(a == c);

	free(c);
	set_destroy(set);
	free(set);
}

TEST(Set, set_union)
{
	int result;
	Set *setu = (Set *)malloc(sizeof(Set));
	Set *set1 = (Set *)malloc(sizeof(Set));
	Set *set2 = (Set *)malloc(sizeof(Set));

	set_init(setu, match, destroy);
	set_init(set1, match, destroy);
	set_init(set2, match, destroy);

	int *a = (int *)malloc(sizeof(int));

	*a = 1;
	EXPECT_EQ(0, set_insert(set1, a));

	int *b = (int *)malloc(sizeof(int));

	*b = 2;
	EXPECT_EQ(0, set_insert(set2, b));


	int *c = (int *)malloc(sizeof(int));

	*c = 1;
	EXPECT_EQ(0, set_insert(set2, c));

	result = set_union(setu, set1, set2);
	EXPECT_EQ(0, result);
	EXPECT_EQ(2, set_size(setu));

	/* TODO: how to release setu to avoid double free items */
	/* set_destroy(setu); */
	set_destroy(set1);
	set_destroy(set2);

	free(set1);
	free(set2);
	free(setu);
}

TEST(Set, set_intersection)
{
	int result;
	Set *seti = (Set *)malloc(sizeof(Set));
	Set *set1 = (Set *)malloc(sizeof(Set));
	Set *set2 = (Set *)malloc(sizeof(Set));

	set_init(seti, match, destroy);
	set_init(set1, match, destroy);
	set_init(set2, match, destroy);

	int *a = (int *)malloc(sizeof(int));

	*a = 1;
	EXPECT_EQ(0, set_insert(set1, a));

	int *b = (int *)malloc(sizeof(int));

	*b = 2;
	EXPECT_EQ(0, set_insert(set1, b));

	int *c = (int *)malloc(sizeof(int));

	*c = 3;
	EXPECT_EQ(0, set_insert(set2, c));

	int *d = (int *)malloc(sizeof(int));

	*d = 2;
	EXPECT_EQ(0, set_insert(set2, d));

	result = set_intersection(seti, set1, set2);
	EXPECT_EQ(0, result);
	EXPECT_EQ(1, set_size(seti));
	EXPECT_EQ(*d, *((int *)list_data(list_head(seti))));

	set_destroy(set1);
	set_destroy(set2);

	free(set1);
	free(set2);
	free(seti);
}

TEST(Set, set_difference)
{
	int result;
	Set *setd = (Set *)malloc(sizeof(Set));
	Set *set1 = (Set *)malloc(sizeof(Set));
	Set *set2 = (Set *)malloc(sizeof(Set));

	set_init(setd, match, destroy);
	set_init(set1, match, destroy);
	set_init(set2, match, destroy);

	int *a = (int *)malloc(sizeof(int));

	*a = 1;
	EXPECT_EQ(0, set_insert(set1, a));

	int *b = (int *)malloc(sizeof(int));

	*b = 2;
	EXPECT_EQ(0, set_insert(set1, b));

	int *c = (int *)malloc(sizeof(int));

	*c = 3;
	EXPECT_EQ(0, set_insert(set1, c));

	int *d = (int *)malloc(sizeof(int));

	*d = 2;
	EXPECT_EQ(0, set_insert(set2, d));

	result = set_difference(setd, set1, set2);
	EXPECT_EQ(0, result);
	EXPECT_EQ(2, set_size(setd));

	set_destroy(set1);
	set_destroy(set2);

	free(set1);
	free(set2);
	free(setd);
}
