#include "dlist.h"
#include <gtest/gtest.h>
#include <stdlib.h>

void destroy(void *data)
{

}

TEST(DList, dlist_init)
{
	DList *list = (DList *)malloc(sizeof(DList));
	dlist_init(list, destroy);
	EXPECT_EQ(0, dlist_size(list));
	EXPECT_TRUE(NULL == dlist_head(list));
	EXPECT_TRUE(NULL == dlist_tail(list));
	EXPECT_TRUE(destroy == list->destroy);

	dlist_destroy(list);
	free(list);
}

TEST(DList, dlist_ins_next)
{
	int result;

	DList *list = (DList *)malloc(sizeof(DList));
	dlist_init(list, destroy);

	int *a = (int *)malloc(sizeof(int));

	*a = 1;
	result = dlist_ins_next(list, NULL, a);
	EXPECT_EQ(0, result);
	EXPECT_EQ(1, dlist_size(list));
	EXPECT_EQ(*a, *((int *)dlist_head(list)->data));
	EXPECT_EQ(*a, *((int *)dlist_tail(list)->data));

	int *b = (int *)malloc(sizeof(int));

	*b = 2;
	result = dlist_ins_next(list, list->head, b);
	EXPECT_EQ(0, result);
	EXPECT_EQ(2, dlist_size(list));
	EXPECT_EQ(*a, *((int *)dlist_head(list)->data));
	EXPECT_EQ(*b, *((int *)dlist_tail(list)->data));

	int *c = (int *)malloc(sizeof(int));

	*c = 3;
	result = dlist_ins_next(list, list->head, c);
	EXPECT_EQ(0, result);
	EXPECT_EQ(3, dlist_size(list));
	EXPECT_EQ(*a, *((int *)dlist_head(list)->data));
	EXPECT_EQ(*c, *((int *)list->head->next->data));	
}
