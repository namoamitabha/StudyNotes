#include "ctype0.h"
#include <gtest/gtest.h>

TEST(CType, isdigit) {
	char *s;
	int c;
	for (s = "0123456789"; *s; ++s) {
		ASSERT_TRUE(isdigit0((int)*s));
		ASSERT_TRUE((isdigit0)((int)*s));
	}
}

/*
Test(CType, isalnum) {

	ASSERT_TRUE(isalnum0((int)'0'));
}
*/
