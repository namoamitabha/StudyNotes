/*
 * Write a version of assert .h, using the version of xassert .c in Figure 1.2,
 * that exactly matches the format shown in the C Standard.
 */

#undef assert

#ifdef NDEBUG
	#define assert(test) ((void)0)
#else
	void _Assert(char *);

	#define _STR(x) _VAL(x)
	#define _VAL(x) #x
	#define assert(test) ((test) ? (void)0 \
			: _Assert(__FILE__ ":" _STR(__LINE__) ":" #test))
#endif
