/* LSB(Lowest Set Bit)を求める */
#define ffs(n) __builtin_ffs(n)	    /* unsigned int */
#define ffsl(n) __builtin_ffsl(n)   /* unsigned long */
#define ffsll(n) __builtin_ffsll(n) /* unsigned long long */
