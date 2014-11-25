#include "ctype0.h"
/* #include "idlen.h" */
#include <stddef.h>

size_t idlen(const char *s)
{
	int len = 0;
	if (!isalpha0(*s))
		return 0;

	for (; *s; ++s) {
		
		if (isalnum0(*s) || (*s == '_'))
			++len;
		else
			return 0;
	}
	return len;
}
