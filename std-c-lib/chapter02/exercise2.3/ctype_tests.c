#include "ctype0.h"
#include <gtest/gtest.h>
#include <limits.h>
#include "idlen.h"

TEST(CType, isalnum)
{
	char *s;

	for (s = "0123456789"; *s; ++s) {
		EXPECT_TRUE((isalnum0)((int)*s));
		EXPECT_TRUE(isalnum0((int)*s));
		EXPECT_TRUE(isxdigit((int)*s));
		EXPECT_TRUE((isxdigit)((int)*s));
	}
}

TEST(CType, isalpha)
{
	EXPECT_TRUE(isalpha0((int)'a'));
	EXPECT_TRUE((isalpha0)((int)'a'));
}

TEST(CType, iscntrl)
{
	EXPECT_TRUE(iscntrl0('\a'));
	EXPECT_TRUE(iscntrl0('\b'));
}

TEST(CType, isdigit)
{
	char *s;

	for (s = "0123456789"; *s; ++s) {
		EXPECT_TRUE(isdigit0((int)*s));
		EXPECT_TRUE((isdigit0)((int)*s));
	}
}

TEST(CType, isgraph)
{
	EXPECT_TRUE(isgraph0('0'));
	EXPECT_TRUE((isgraph0)('0'));
}

TEST(CType, islower)
{
	char *s;

	for (s = "abcdefghijklmnopqrstuvwxyz"; *s; ++s) {
		EXPECT_TRUE(islower0(*s));
		EXPECT_TRUE((islower0)(*s));
	}
}

TEST(CType, isprint)
{
	EXPECT_TRUE(isprint0('&'));
	EXPECT_TRUE(isprint0(' '));
	EXPECT_TRUE((isprint0)(' '));
}

TEST(CType, ispunct)
{
	char *s;

	for (s = "!\"#%&'();<=>?[\\]*+,-./:^_{|}~"; *s; ++s) {
		EXPECT_TRUE(ispunct0(*s));
		EXPECT_TRUE((ispunct0)(*s));
	}
}

TEST(CType, isspace)
{
	char *s;

	for (s = "\f\n\r\t\v"; *s; ++s) {
		EXPECT_TRUE(isspace0(*s));
		EXPECT_TRUE((isspace0)(*s));
		EXPECT_TRUE(iscntrl(*s));
		EXPECT_TRUE((iscntrl)(*s));
	}
}

TEST(CType, isupper)
{
	char *s;

	for (s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; *s; ++s) {
		EXPECT_TRUE(isupper0(*s));
		EXPECT_TRUE((isupper0)(*s));
	}
}

TEST(CType, isxdigit)
{
	char *s;

	for (s = "0123456789abcdefABCDEF"; *s; ++s) {
		EXPECT_TRUE(isxdigit0(*s));
		EXPECT_TRUE((isxdigit0)(*s));
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
		if ((isdigit0)(c))
			EXPECT_TRUE((isalnum0)(c));

		if (isupper0(c))
			EXPECT_TRUE(isalpha0(c));

		if (islower0(c))
			EXPECT_TRUE(isalpha0(c));

		if (isalpha0(c))
			EXPECT_TRUE(isalnum0(c) && !isdigit0(c));

		if (isalnum(c))
			EXPECT_TRUE(isgraph0(c) && !ispunct0(c));

		if (ispunct0(c))
			EXPECT_TRUE(isgraph0(c));

		if (isgraph0(c))
			EXPECT_TRUE(isprint0(c));

		if (isspace0(c))
			EXPECT_TRUE((c == ' ') || !isprint0(c));

		if (iscntrl0(c))
			EXPECT_TRUE(!isalnum0(c));
	}
}

TEST(CType, Exercise2_3)
{
	EXPECT_EQ(1, idlen("a"));
	EXPECT_EQ(0, idlen("_abc"));
	EXPECT_EQ(5, idlen("abcd2"));
	EXPECT_EQ(0, idlen("abc*e"));
	EXPECT_EQ(0, idlen("1abc"));
	EXPECT_EQ(6, idlen("a_abc_"));
}
