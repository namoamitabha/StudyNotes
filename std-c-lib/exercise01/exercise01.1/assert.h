/*
 * Write a version of assert .h, using the version of xassert .c in Figure 1.2,
 * that exactly matches the format shown in the C Standard.
 */

#undef assert

#define _STR(x) _VAL(x)
#define _VAL(x) #x

#ifdef NDEBUG
	#define assert(x) ((void)0)
#else
	#define assert(x) (x ? ((void)0) : \
		   _Assert(__FILE__ ":" _VAL(_STR(__LINE__))))
#endif
