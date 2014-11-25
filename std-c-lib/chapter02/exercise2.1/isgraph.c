#include "ctype0.h"

int (isgraph0) (int c)
{
	return (_Ctype[c] & (_DI|_LO|_PU|_UP|_XA));
}
