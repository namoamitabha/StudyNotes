#include "clist.h"
#include <gtest/gtest.h>
#include <stdlib.h>

#define DEBUG

void destroy(void *data)
{
	free(data);
}

void clist_print(CList *list)
{
#ifdef DEBUG
	int i = 0;
	CListElmt *current = clist_head(list);

	while (i < clist_size(list)) {
		printf("%d\n", *((int *)clist_data(current)));
		current = current->next;
		++i;
	}
#endif
}

TEST(CList, clist_init)
{
	CList *list = (CList *)malloc(sizeof(CList));
	clist_init(list, destroy);
	EXPECT_EQ(0, clist_size(list));
	EXPECT_TRUE(NULL == list->head);
	EXPECT_TRUE(destroy == list->destroy);

	clist_destroy(list);
	free(list);
}

TEST(CList, clist_ins_next)
{
	int result;

	CList *list = (CList *)malloc(sizeof(CList));
	clist_init(list, destroy);

	int *a = (int *)malloc(sizeof(int));
	*a = 1;
	result = clist_ins_next(list, NULL, a);
	EXPECT_EQ(0, result);
	EXPECT_EQ(1, clist_size(list));
	EXPECT_EQ(*a, *((int *)clist_data(clist_head(list))));
	EXPECT_TRUE( clist_next(list->head) == clist_head(list));

	int *b = (int *)malloc(sizeof(int));
	*b = 2;

	result = clist_ins_next(list, NULL, b);
	EXPECT_EQ(-1, result);

	result = clist_ins_next(list, clist_head(list), b);
	EXPECT_EQ(0, result);
	EXPECT_EQ(2, clist_size(list));
	EXPECT_EQ(*a, *((int *)clist_data(clist_head(list))));
	EXPECT_EQ(*b, *((int *)clist_data(clist_next(clist_head(list)))));
	EXPECT_TRUE(clist_head(list) 
		    == clist_next(clist_next(clist_head(list))));

	int *c = (int *)malloc(sizeof(int));
	*c = 3;
	result = clist_ins_next(list, clist_head(list), c);
	EXPECT_EQ(0, result);
	EXPECT_EQ(3, clist_size(list));
	EXPECT_EQ(*a, *((int *)clist_data(clist_head(list))));
	EXPECT_EQ(*c, *((int *)clist_head(list)->next->data));
	EXPECT_EQ(*b, *((int *)list->head->next->next->data));
	EXPECT_TRUE(clist_head(list)
		== list->head->next->next->next);

	clist_destroy(list);
	free(list);	
}

TEST(CList, clist_rem_next)
{
	int result;
	void *data;
	CList *list = (CList *)malloc(sizeof(CList));
	clist_init(list, destroy);

	result = clist_rem_next(list, NULL, &data);
	EXPECT_EQ(-1, result);

	int *a;
	for (int i = 0; i < 3; ++i) {
		a = (int *)malloc(sizeof(int));
		*a = i;
		clist_ins_next(list, clist_head(list), a);
	}
	clist_print(list);

	result = clist_rem_next(list, clist_head(list), &data);
	EXPECT_EQ(0, result);
	EXPECT_EQ(2, clist_size(list));
	EXPECT_EQ(2, *((int *)data));

	result = clist_rem_next(list, clist_head(list), &data);
	EXPECT_EQ(0, result);
	EXPECT_EQ(1, clist_size(list));
	EXPECT_EQ(1, *((int *)data));
	EXPECT_TRUE(clist_head(list)
		    == clist_head(list)->next);

	result = clist_rem_next(list, clist_head(list), &data);
	EXPECT_EQ(0, result);
	EXPECT_EQ(0, clist_size(list));
	EXPECT_EQ(0, *((int *)data));
	EXPECT_TRUE(NULL == clist_head(list));

	clist_destroy(list);
	free(list);
}

TEST(CList, clist_destroy)
{
	int *a;
	CList *list = (CList *)malloc(sizeof(int));

	clist_init(list, destroy);

	for (int i = 0; i < 10; ++i) {
		a = (int *)malloc(sizeof(int));
		*a = i;
		clist_ins_next(list, clist_head(list), a);
	}

	clist_print(list);

	clist_destroy(list);
//TODO: why here cannot free the list
	/* free(list); */
}
