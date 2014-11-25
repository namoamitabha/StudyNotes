#include "ctype0.h"
#include <stdio.h>

int (isalnum0)(int c)
{
	if (c == EOF)
		return 0;
	else
		return (_Ctype[(unsigned char)c] & (_DI|_LO|_UP|_XA));
}
