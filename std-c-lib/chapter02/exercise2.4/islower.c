#include "ctype0.h"

int (islower0) (int c)
{
	return (_Ctype[c] & (_LO));
}
