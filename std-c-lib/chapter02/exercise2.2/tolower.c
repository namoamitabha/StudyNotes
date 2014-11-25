#include "ctype0.h"
#include <stdio.h>

int (tolower0) (int c)
{
	if (c == EOF)
		return 0;
	else
		return _Tolower[(unsigned char)c];
}
