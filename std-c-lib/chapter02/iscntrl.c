#include "ctype0.h"

int (iscntrl0) (int c) 
{
	return (_Ctype[c] & (_BB|_CN));
}
