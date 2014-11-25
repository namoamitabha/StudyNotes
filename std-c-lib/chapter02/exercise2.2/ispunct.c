#include "ctype0.h"

int (ispunct0) (int c)
{
	return (_Ctype[c] & (_PU));
}
