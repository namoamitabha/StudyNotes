#include "ctype0.h"
#include <gtest/gtest.h>
#include <limits.h>

TEST(CType, isalnum)
{
	ASSERT_TRUE((isalnum0)((int)'0'));
	ASSERT_TRUE(isalnum0((int)'0'));
}

TEST(CType, isalpha)
{
	ASSERT_TRUE(isalpha0((int)'a'));
	ASSERT_TRUE((isalpha0)((int)'a'));
}

TEST(CType, iscntrl)
{
	ASSERT_TRUE(iscntrl0('\a'));
	ASSERT_TRUE(iscntrl0('\b'));
}

TEST(CType, isdigit)
{
	char *s;

	for (s = "0123456789"; *s; ++s) {
		ASSERT_TRUE(isdigit0((int)*s));
		ASSERT_TRUE((isdigit0)((int)*s));
	}
}

TEST(CType, isgraph)
{
	ASSERT_TRUE(isgraph0('0'));
	ASSERT_TRUE((isgraph0)('0'));
}

TEST(CType, islower)
{
	ASSERT_TRUE(islower0('a'));
	ASSERT_FALSE(islower0('A'));
	ASSERT_TRUE((islower0)('a'));
	ASSERT_FALSE((islower0)('A'));
}

TEST(CType, isprint)
{
	ASSERT_TRUE(isprint0('&'));
}

TEST(CType, ispunct)
{
	ASSERT_TRUE(ispunct0(','));
	ASSERT_TRUE((ispunct0)(','));
}

TEST(CType, isspace)
{
	ASSERT_TRUE(isspace0(' '));
	ASSERT_TRUE((isspace0)(' '));
}

TEST(CType, isupper)
{
	ASSERT_TRUE(isupper0('A'));
	ASSERT_TRUE((isupper0)('A'));
}

TEST(CType, isxdigit)
{
	ASSERT_TRUE(isxdigit0('F'));
	ASSERT_TRUE((isxdigit0)('F'));
}

TEST(CType, ClassMembership)
{
	int c;

	for (c = EOF; c <= UCHAR_MAX; ++c) {
		if ((isdigit)(c))
			ASSERT_TRUE((isalnum)(c));
	}
}
