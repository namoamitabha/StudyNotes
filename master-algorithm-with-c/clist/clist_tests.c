#include "clist.h"
#include <gtest/gtest.h>
#include <stdlib.h>

void destroy(void *data)
{

}

TEST(CList, clist_init)
{
	CList *list = (CList *)malloc(sizeof(CList));
	clist_init(list, destroy);
	EXPECT_EQ(0, clist_size(list));
	EXPECT_TRUE(NULL == list->head);
	EXPECT_TRUE(destroy == list->destroy);

	free(list);
}

TEST(CList, clist_ins_next)
{

}
