#include "ctype0.h"
#include <gtest/gtest.h>
#include <limits.h>

TEST(CType, isalnum)
{
	char *s;
	for (s = "0123456789"; *s; ++s) {
		ASSERT_TRUE((isalnum0)((int)*s));
		ASSERT_TRUE(isalnum0((int)*s));
	}
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
	char *s;

	for (s = "abcdefghijklmnopqrstuvwxyz"; *s; ++s) {
		ASSERT_TRUE(islower0(*s));
		ASSERT_TRUE((islower0)(*s));
	}
}

TEST(CType, isprint)
{
	ASSERT_TRUE(isprint0('&'));
}

TEST(CType, ispunct)
{
	char *s;
	for (s = "!\"#%&'();<=>?[\\]*+,-./:^_{|}~"; *s; ++s) {
		ASSERT_TRUE(ispunct0(*s));
		ASSERT_TRUE((ispunct0)(*s));
	}
}

TEST(CType, isspace)
{
	char *s;
	for (s = "\f\n\r\t\v"; *s; ++s) {
		ASSERT_TRUE(isspace0(*s));
		ASSERT_TRUE((isspace0)(*s));
	}
}

TEST(CType, isupper)
{
	char *s;
	for (s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; *s; ++s) {
		ASSERT_TRUE(isupper0(*s));
		ASSERT_TRUE((isupper0)(*s));
	}
}

TEST(CType, isxdigit)
{
	char *s;
	for (s = "0123456789abcdefABCDEF"; *s; ++s) {
		ASSERT_TRUE(isxdigit0(*s));
		ASSERT_TRUE((isxdigit0)(*s));
	}
}

TEST(CType, tolower)
{
	EXPECT_EQ('a', tolower0('A'));
	EXPECT_EQ('a', (tolower0)('A'));
}

TEST(CType, toupper)
{
	EXPECT_EQ('Z', toupper0('z'));
	EXPECT_EQ('Z', (toupper0)('z'));
}

TEST(CType, ClassMembership)
{
	int c;

	for (c = EOF; c <= UCHAR_MAX; ++c) {
		if ((isdigit)(c))
			ASSERT_TRUE((isalnum)(c));
	}
}
