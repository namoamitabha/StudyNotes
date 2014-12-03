#include "ctype0.h"
#include  <stddef.h>

size_t detab(char *dest, const char *src)
{
	int len = 0;

	for (int j = 0; *(src + j); ++j) {
		if (*(src + j) == '\t') {
			for (int i = 0; i < 4; ++i) {
				*dest = ' ';
				++dest;
				++len;
			}			
		} else {
			*dest = *(src + j);
			++dest;
			++len;
		}
	}
	return len;
}
