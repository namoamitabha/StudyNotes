#include "ctype0.h"
#include <stdio.h>

int main(void)
{
	char *s;

	for (s = "Hello, world!\n"; *s; ++s) {
		printf("%c:\n", *s);
		if (!isalnum0(*s))
			printf("isalnum\n");

		if (!isalpha0(*s))
			printf("isalpha\n");

		if (!iscntrl0(*s))
			printf("iscntrl\n");

		if (!isdigit0(*s))
			printf("isdigit\n");

		if (!isgraph0(*s))
			printf("isgraph\n");

		if (!islower0(*s))
			printf("islower\n");

		if (!isprint0(*s))
			printf("isprint\n");

		if (!ispunct0(*s))
			printf("ispunct\n");

		if (!isspace0(*s))
			printf("isspace\n");

		if (!isupper0(*s))
			printf("isupper\n");

		if (!isxdigit0(*s))
			printf("isxdigit\n");

		printf("\n********\n");
	}
}
