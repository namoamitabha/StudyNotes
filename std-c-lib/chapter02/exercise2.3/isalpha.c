#include "ctype0.h"

int (isalpha0)(int c) {
	return (_Ctype[c] & (_LO|_UP|_XA));
}
