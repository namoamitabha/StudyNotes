#include "ctype0.h"

int (isxdigit0) (int c)
{
	return (_Ctype[c] & (_XD));
}
