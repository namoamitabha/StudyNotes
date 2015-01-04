#include "list.h"
#include <gtest/gtest.h>
#include <limits.h>
#include <stdlib.h>

void destroy(void *data)
{
}

TEST(SList, list_init0)
{
	List *list = (List *)malloc(sizeof(List));
	list_init(list, destroy);
	EXPECT_EQ(list->size, 0);
	EXPECT_TRUE(list->head == NULL);
	EXPECT_TRUE(list->tail == NULL);
	EXPECT_TRUE(list->destroy == destroy);
}

TEST(SList, list_init1)
{
	List *list = (List *)malloc(sizeof(List));
	list_init(list, NULL);
	EXPECT_EQ(list->size, 0);
	EXPECT_TRUE(list->head == NULL);
	EXPECT_TRUE(list->tail == NULL);
	EXPECT_TRUE(list->destroy == NULL);
}
