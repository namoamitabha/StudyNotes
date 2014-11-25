#include "ctype0.h"

int (isprint0) (int c)
{
	return (_Ctype[c] & (_DI|_LO|_PU|_SP|_UP|_XA));
}
