#include "ctype0.h"
#include <gtest/gtest.h>
#include <limits.h>

TEST(CType, isalnum) {
	ASSERT_TRUE((isalnum0)((int)'0'));
	ASSERT_TRUE(isalnum0((int)'0'));
}

TEST(CType, isalpha) {
	ASSERT_TRUE(isalpha0((int)'a'));
	ASSERT_TRUE((isalpha0)((int)'a'));
}

TEST(CType, iscntrl0) {
	ASSERT_TRUE(iscntrl0('\a'));
	ASSERT_TRUE(iscntrl0('\b'));
}

TEST(CType, isdigit) {
	char *s;
	for (s = "0123456789"; *s; ++s) {
		ASSERT_TRUE(isdigit0((int)*s));
		ASSERT_TRUE((isdigit0)((int)*s));
	}
}

TEST(CType, isgraph) {
	ASSERT_TRUE(isgraph0('0'));
	ASSERT_TRUE((isgraph0)('0'));
}

TEST(CType, ClassMembership) {
	int c;
	for (c = EOF; c <= UCHAR_MAX; ++c) {
		if ((isdigit)(c))
			ASSERT_TRUE((isalnum)(c));
	}
}
