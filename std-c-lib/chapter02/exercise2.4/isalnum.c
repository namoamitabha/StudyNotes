#include "ctype0.h"

int (isalnum0)(int c)
{
	return (_Ctype[c] & (_DI|_LO|_UP|_XA));
}
