#include "list.h"
#include <gtest/gtest.h>
#include <limits.h>
#include <stdlib.h>

/* #define DEBUG */

void destroy(void *data)
{
	if (data != NULL)
		free(data);
}

void list_print(List *list)
{
#ifdef DEBUG
	ListElmt *current = list->head;
	int i = 1;

	while (i <= list->size) {
		if (NULL != current)
			printf("%d:%d\n", i, *(int *)current->data);

		current = current->next;
		++i;
	}
	printf("=====\n");
#endif
}

TEST(List, list_destroy0)
{
	List *list = (List *)malloc(sizeof(List));

	list_init(list, destroy);

	int *a = (int *)malloc(sizeof(int));

	*a = 1;
	list_ins_next(list, NULL, a);

	list_destroy(list);
	EXPECT_EQ(0, list->size);
	EXPECT_TRUE(list->head == NULL);
	EXPECT_TRUE(list->tail == NULL);

	free(list);
}

TEST(List, list_destroy1)
{
	List *list = (List *)malloc(sizeof(List));

	list_init(list, destroy);
	list_destroy(list);

	EXPECT_EQ(0, list->size);
	EXPECT_TRUE(list->head == NULL);
	EXPECT_TRUE(list->tail == NULL);

	free(list);
}

TEST(List, list_init0)
{
	List *list = (List *)malloc(sizeof(List));

	list_init(list, destroy);
	EXPECT_EQ(list->size, 0);
	EXPECT_TRUE(list->head == NULL);
	EXPECT_TRUE(list->tail == NULL);
	EXPECT_TRUE(list->destroy == destroy);

	list_destroy(list);
	free(list);
}

TEST(List, list_init1)
{
	List *list = (List *)malloc(sizeof(List));

	list_init(list, NULL);
	EXPECT_EQ(list->size, 0);
	EXPECT_TRUE(list->head == NULL);
	EXPECT_TRUE(list->tail == NULL);
	EXPECT_TRUE(list->destroy == NULL);

	list_destroy(list);
	free(list);
}

TEST(List, list_ins_next0)
{
	int result;
	List *list = (List *)malloc(sizeof(List));

	list_init(list, destroy);

	int *a = (int *)malloc(sizeof(int));
	*a = 1;
	result = list_ins_next(list, NULL, a);

	EXPECT_EQ(result, 0);
	EXPECT_EQ(list->size, 1);
	EXPECT_EQ(*(int *)list_data(list->head), *a);
	EXPECT_EQ(*(int *)list_data(list->tail), *a);

	list_print(list);

	int *b = (int *)malloc(sizeof(int));
	*b = 2;
	result = list_ins_next(list, NULL, b);

	EXPECT_EQ(result, 0);
	EXPECT_EQ(list->size, 2);
	EXPECT_EQ(*(int *)list_data(list->head), *b);
	EXPECT_EQ(*(int *)list_data(list->tail), *a);

	list_print(list);

	int *c = (int *)malloc(sizeof(int));
	*c = 0;
	result = list_ins_next(list, list->tail, c);

	EXPECT_EQ(result, 0);
	EXPECT_EQ(list->size, 3);
	EXPECT_EQ(*(int *)list_data(list->head), *b);
	EXPECT_EQ(*(int *)list_data(list->tail), *c);

	list_print(list);

	int *d = (int *)malloc(sizeof(int));
	*d = 3;
	result = list_ins_next(list, list->head, d);

	EXPECT_EQ(result, 0);
	EXPECT_EQ(list->size, 4);
	EXPECT_EQ(*(int *)list_data(list->head), *b);
	EXPECT_EQ(*(int *)list_data(list->head->next), *d);

	list_print(list);

	list_destroy(list);
	free(list);
}

TEST(List, list_rem_next)
{
	int result;
	List *list = (List *)malloc(sizeof(List));

	list_init(list, destroy);

	void *data = NULL;

	result = list_rem_next(list, NULL, &data);
	EXPECT_EQ(-1, result);
	EXPECT_TRUE(data == NULL);

	int *a = (int *)malloc(sizeof(int));
	*a = 1;
	list_ins_next(list, NULL, a);
	result = list_rem_next(list, list->tail, &data);
	EXPECT_EQ(-1, result);

	result = list_rem_next(list, NULL, &data);
	EXPECT_EQ(0, result);
	EXPECT_TRUE(list->head == NULL);
	EXPECT_TRUE(list->tail == NULL);
	EXPECT_EQ(*a, *(int *)data);
	EXPECT_EQ(0, list->size);

	int i;

	for (i = 0; i < 10; ++i) {
		int *t = (int *)malloc(sizeof(int));
		*t = i;
		list_ins_next(list, list->tail, t);
	}
	list_print(list);


	result = list_rem_next(list, NULL, &data);
	EXPECT_EQ(0, result);
	EXPECT_EQ(0, *(int *)data);
	EXPECT_EQ(9, list->size);

	list_destroy(list);
	free(list);
}

TEST(List, performance)
{
	int result;
	int *tmp;
	int i;
	const int size = 1000000;
	List *list = (List *)malloc(sizeof(List));

	list_init(list, destroy);

	for (i = 0; i < size; ++i) {
		tmp = (int *)malloc(sizeof(int));
		*tmp = i;

		list_ins_next(list, NULL, tmp);
	}
	EXPECT_EQ(size, list_size(list));
	list_print(list);

	list_destroy(list);
	free(list);
}
