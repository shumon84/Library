/* CTZ(Count Trailing Zero)最上位ビットから連続する0を求める */
#define ctz(n) __builtin_ctz(n)	    /* unsigned int */
#define ctzl(n) __builtin_ctzl(n)   /* unsigned long */
#define ctzll(n) __builtin_ctzll(n) /* unsigned long long */
