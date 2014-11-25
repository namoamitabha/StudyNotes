#include "ctype0.h"
#include <stdio.h>

int (isspace0) (int c)
{
	if (c == EOF)
		return 0;
	else
		return (_Ctype[(unsigned char)c] & (_CN|_SP|_XS));
}
