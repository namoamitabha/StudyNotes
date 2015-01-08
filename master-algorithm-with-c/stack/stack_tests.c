#include "stack.h"
#include <gtest/gtest.h>
#include <limits.h>
#include <stdlib.h>


void destroy(void *data)
{
	free(data);
}

TEST(Stack, stack_push_stack_pop)
{
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	stack_init(stack, destroy);

	int result;

	int *a = (int *)malloc(sizeof(int));
	*a = 1;

	result = stack_push(stack, a);
	EXPECT_EQ(0, result);
	EXPECT_EQ(1, stack_size(stack));
	EXPECT_EQ(*a, *((int *)stack_peek(stack)));

	int *b = (int *)malloc(sizeof(int));
	*b = 2;

	result = stack_push(stack, b);
	EXPECT_EQ(0, result);
	EXPECT_EQ(2, stack_size(stack));
	EXPECT_EQ(*b, *((int *)stack_peek(stack)));

	void *data;

	result = stack_pop(stack, &data);
	EXPECT_EQ(0, result);
	EXPECT_EQ(1, stack_size(stack));
	EXPECT_EQ(*b, *((int *)data));

	result = stack_pop(stack, &data);
	EXPECT_EQ(0, result);
	EXPECT_EQ(0, stack_size(stack));
	EXPECT_EQ(*a, *((int *)data));

	result = stack_pop(stack, &data);
	EXPECT_EQ(-1, result);

	stack_destroy(stack);
	free(stack);
}
