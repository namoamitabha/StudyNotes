#include "ctype0.h"
#include <stdio.h>

int (toupper0) (int c)
{
	if (c == EOF)
		return 0;
	else
		return _Toupper[(unsigned char)c];
}
