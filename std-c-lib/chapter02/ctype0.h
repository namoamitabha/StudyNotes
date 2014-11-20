#ifndef _CTYPE
#define _CTYPE

#define _XA	0x200 /* extra alphabetic */
#define _XS	0x100 /* extra space */
#define _BB	0x80 /* BEL, BS, etc. */
#define _CN	0x40 /* CR, FF, HT, NL, VT */
#define _DI	0x20 /* '0'-'9' */
#define _LO	0x10 /* 'a'-'z'*/
#define _PU	0x08 /* punctuation */
#define _SP	0x04 /* space */
#define _UP	0x02 /* 'A'-'Z' */
#define _XD	0x01 /* '0'-'9', 'A'-'F', 'a'-'f'*/

int isalnum0(int), isdigit0(int);
/*
int isalnum(int), isalpha(int), iscntrl(int), isdigit(int);
int isgraph(int), islower(int), isprint(int), ispunct(int);
int isspace(int), isupper(int), isxdigit(int);
int tolower(int), toupper(int);
*/

extern const short *_Ctype; //, *_Tolower, *_Toupper;

#define isalnum0(c) (_Ctype[(int)(c)] & (_DI|_LO|_UP|_XA))

#define isalpha0(c) (_Ctype[(int)c] & (_LO|_UP|_XA))
/*
#define iscntrl(c) (_Ctype[(int)c] & (_BB|_CN))
*/
#define isdigit0(c) (_Ctype[(int)(c)] & (_DI))
/*
#define isgraph(c) (_Ctype[(int)c] & (_DI|_LO|_PU|_UP|_XA))
#define islower(c) (_Ctype[(int)c] & (_LO))
#define isprint(c) (_Ctype[(int)c] & (_DI|_LO|_PU|_SP|_UP|_XA))
#define ispunct(c) (_Ctype[(int)c] & (_PU))
#define isspace(c) (_Ctype[(int)c] & (_CN|_SP|_XS))
#define isupper(c) (_Ctype[(int)c] & (_UP))
#define isxdigit(c) (_Ctype[(int)c] & (_XD))
#define tolower(c) _Tolower[(int)c]
#define toupper(c) _Toupper[(int)c]
*/
#endif
