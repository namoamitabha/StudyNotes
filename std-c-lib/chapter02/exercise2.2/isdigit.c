#include "ctype0.h"

int (isdigit0)(int c)
{
	return (_Ctype[c] & _DI);
}
