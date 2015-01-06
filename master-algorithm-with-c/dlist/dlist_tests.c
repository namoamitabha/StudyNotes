#include "dlist.h"
#include <gtest/gtest.h>
#include <stdlib.h>

/* #define DEBUG */

void destroy(void *data)
{
	/* printf("destroy:%d\n", *((int *)data)); */
	free(data);
}

void print_list(DList *list)
{
#ifdef DEBUG
	int i = 0;

	DListElmt *current = list->head;

	while (NULL != current) {
		printf("%d:%d\n", ++i, *((int *)current->data));
		current = current->next;
	}
	printf("=====\n");
#endif
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
	result = dlist_ins_next(list, NULL, b);
	EXPECT_EQ(-1, result);

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

	print_list(list);

	int *d = (int *)malloc(sizeof(int));

	*d = 4;
	result = dlist_ins_next(list, list->tail, d);
	EXPECT_EQ(0, result);
	EXPECT_EQ(4, dlist_size(list));
	EXPECT_EQ(*a, *((int *)dlist_head(list)->data));
	EXPECT_EQ(*d, *((int *)dlist_tail(list)->data));

	print_list(list);

	dlist_destroy(list);
	free(list);
}

TEST(DList, dlist_ins_prev)
{
	int result;

	DList *list = (DList *)malloc(sizeof(DList));

	dlist_init(list, destroy);
	
	int *a = (int *)malloc(sizeof(int));

	*a = 1;
	result = dlist_ins_prev(list, NULL, a);
	EXPECT_EQ(0, result);
	EXPECT_EQ(1, dlist_size(list));
	EXPECT_EQ(*a, *((int *)dlist_head(list)->data));
	EXPECT_EQ(*a, *((int *)dlist_tail(list)->data));
	
	int *b = (int *)malloc(sizeof(int));

	result = dlist_ins_prev(list, NULL, a);
	EXPECT_EQ(-1, result);

	*b = 2;
	result = dlist_ins_prev(list, dlist_head(list), b);
	EXPECT_EQ(0, result);
	EXPECT_EQ(2, dlist_size(list));
	EXPECT_EQ(*b, *((int *)dlist_head(list)->data));
	EXPECT_EQ(*a, *((int *)dlist_tail(list)->data));
	print_list(list);

	int *c = (int *)malloc(sizeof(int));

	*c = 3;
	result = dlist_ins_prev(list, dlist_tail(list), c);

	print_list(list);
	EXPECT_EQ(0, result);
	EXPECT_EQ(*b, *((int *)dlist_head(list)->data));
	EXPECT_EQ(*c, *((int *)list->head->next->data));
	EXPECT_EQ(*a, *((int *)dlist_tail(list)->data));

	int *d = (int *)malloc(sizeof(int));

	*d = 4;
	result = dlist_ins_prev(list, dlist_head(list)->next, d);
	EXPECT_EQ(0, result);
	EXPECT_EQ(4, dlist_size(list));
	EXPECT_EQ(*b, *((int *)dlist_head(list)->data));
	EXPECT_EQ(*d, *((int *)dlist_head(list)->next->data));
	EXPECT_EQ(*c, *((int *)dlist_tail(list)->prev->data));
	EXPECT_EQ(*a, *((int *)dlist_tail(list)->data));

	print_list(list);

	dlist_destroy(list);
	free(list);
}

TEST(DList, dlist_remove)
{
	int result;
	void *data;

	DList *list = (DList *)malloc(sizeof(DList));

	dlist_init(list, destroy);

	result = dlist_remove(list, NULL, &data);
	EXPECT_EQ(-1, result);

	int *a = (int *)malloc(sizeof(int));
	
	*a = 1;
	result = dlist_ins_next(list, NULL, a);
	EXPECT_EQ(0, result);

	print_list(list);

	result = dlist_remove(list, list->head, &data);
	EXPECT_EQ(0, result);
	EXPECT_EQ(0, dlist_size(list));
	EXPECT_EQ(*a, *((int *)data));
	EXPECT_TRUE(NULL == list->head);
	EXPECT_TRUE(NULL == list->tail);


	result = dlist_ins_next(list, NULL, a);

	int *b = (int *)malloc(sizeof(int));
	
	*b = 2;
	result = dlist_ins_next(list, dlist_tail(list), b);

	int *c = (int *)malloc(sizeof(int));

	*c = 3;
	result = dlist_ins_next(list, dlist_tail(list), c);
	
	int *d = (int *)malloc(sizeof(int));
	
	*d = 4;
	result = dlist_ins_next(list, dlist_tail(list), d);
	
	result = dlist_remove(list, dlist_tail(list), &data);
	EXPECT_EQ(0, result);
	EXPECT_EQ(*d, *((int *)data));

	result = dlist_remove(list, dlist_tail(list)->prev, &data);
	EXPECT_EQ(0, result);
	EXPECT_EQ(*b, *((int *)data));

	result = dlist_remove(list, dlist_head(list), &data);
	EXPECT_EQ(0, result);
	EXPECT_EQ(*a, *((int *)data));

	result = dlist_remove(list, dlist_head(list), &data);
	EXPECT_EQ(0, result);
	EXPECT_EQ(*c, *((int *)data));

	dlist_destroy(list);
	free(list);
}

TEST(DList, dlist_destroy)
{
	int result;

	DList *list = (DList *)malloc(sizeof(DList));

	dlist_init(list, destroy);

	int *a;
	int i;

	for (i = 0; i < 10; i++) {
		a = (int *)malloc(sizeof(int));
		*a = i;
		result = dlist_ins_next(list, list->head, a);
	}

	print_list(list);
	
	dlist_destroy(list);

	free(list);
}
