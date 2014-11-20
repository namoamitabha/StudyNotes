#include "ctype0.h"
#include <gtest/gtest.h>

TEST(CType, isalnum) {
	ASSERT_TRUE((isalnum0)((int)'0'));
	ASSERT_TRUE(isalnum0((int)'0'));
}

TEST(CType, isalpha) {
	ASSERT_TRUE(isalpha0((int)'a'));
}

TEST(CType, isdigit) {
	char *s;
	int c;
	for (s = "0123456789"; *s; ++s) {
		ASSERT_TRUE(isdigit0((int)*s));
		ASSERT_TRUE((isdigit0)((int)*s));
	}
}


