/*
 * Write a version of xassert. C, using the version of assert .h in Figure 1.1,
 * that exactly matches the format shown in the C Standard.
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void _Assert(char* msg)
{
	fputs(msg, stderr);
	fputs(" -- assertion failed\n", stderr);
	abort();
}
