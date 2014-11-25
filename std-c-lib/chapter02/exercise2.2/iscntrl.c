#include "ctype0.h"
#include <stdio.h>

int (iscntrl0) (int c)
{
	if (c == EOF)
		return 0;
	else
		return (_Ctype[(unsigned char)c] & (_BB|_CN));
}
