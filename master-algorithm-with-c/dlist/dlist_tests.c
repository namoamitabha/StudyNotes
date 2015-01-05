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
}

TEST(DList, dlist_ins_next)
{

}
