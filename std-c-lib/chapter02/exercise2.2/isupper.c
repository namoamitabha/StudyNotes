#include "ctype0.h"

int (isupper0) (int c)
{
	return (_Ctype[c] & (_UP));
}
