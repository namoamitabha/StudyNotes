#include "ctype0.h"
#include <stdio.h>

int (isdigit0)(int c)
{
	if (c == EOF)
		return 0;
	else
		return (_Ctype[(unsigned char)c] & _DI);
}
