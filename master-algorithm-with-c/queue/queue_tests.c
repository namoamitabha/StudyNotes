#include "queue.h"

#include <gtest/gtest.h>
#include <limits.h>
#include <stdlib.h>

void destroy(void *data)
{
	free(data);
}

TEST(Queue, queue_enqueue_queue_dequeue)
{
	int result;

	Queue *queue = (Queue *)malloc(sizeof(Queue));
	queue_init(queue, destroy);

	int *a = (int *)malloc(sizeof(int));
	*a = 1;

	result = queue_enqueue(queue, a);
	EXPECT_EQ(0, result);
	EXPECT_EQ(1, queue_size(queue));
	EXPECT_EQ(*a, *((int *)queue_peek(queue)));

	int *b = (int *)malloc(sizeof(int));
	*b = 2;

	result = queue_enqueue(queue, b);
	EXPECT_EQ(0, result);
	EXPECT_EQ(2, queue_size(queue));
	EXPECT_EQ(*a, *((int *)queue_peek(queue)));

	void *data;
	result = queue_dequeue(queue, &data);
	EXPECT_EQ(0, result);
	EXPECT_EQ(1, queue_size(queue));
	EXPECT_EQ(*a, *((int *)data));
	EXPECT_EQ(*b, *((int *)queue_peek(queue)));

	result = queue_dequeue(queue, &data);
	EXPECT_EQ(0, result);
	EXPECT_EQ(0, queue_size(queue));
	EXPECT_EQ(*b, *((int *)data));

	result = queue_dequeue(queue, &data);
	EXPECT_EQ(-1, result);

	queue_destroy(queue);
	free(queue);
}
