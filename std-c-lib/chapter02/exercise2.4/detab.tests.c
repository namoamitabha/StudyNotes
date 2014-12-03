#include "ctype0.h"
#include <gtest/gtest.h>
#include <limits.h>
#include "detab.h"

TEST(CType, Exercise2_4_Test1)
{
	char dest[100] = "\0";
	char *src = "	";
	EXPECT_EQ(4, detab(dest, src));
	EXPECT_EQ(4, strlen(dest));

	strcpy(src, "This is second test	.");
	EXPECT_EQ(25, detab(dest, src));
}

TEST(CType, Exercise2_4_Test2)
{
	char dest[100] = "\0";
	char src[100] = "	\0";
	EXPECT_TRUE(0);
	EXPECT_EQ(4, detab(dest, src));
	EXPECT_EQ(4, strlen(dest));
	printf("%d\n", strlen(dest));

	strcpy(src, "This is second test	.\0");
	EXPECT_EQ(26, detab(dest, src));
	printf("%d\n", strlen(dest));
}

TEST(CType, Exercise2_4_Test3)
{
	EXPECT_FALSE(0);
	EXPECT_EQ(1, 0);
}
