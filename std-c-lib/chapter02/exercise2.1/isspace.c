#include "ctype0.h"

int (isspace0) (int c)
{
	return (_Ctype[c] & (_CN|_SP|_XS));
}
