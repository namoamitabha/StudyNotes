#include "mctype.h"
#include <gtest/gtest.h>

TEST(CType, isdigit) {
	char *s;
	int c;
	for (s = "0123456789"; *s; ++s) {
		ASSERT_TRUE(isdigit0((int)*s));
	}
}
