/* CLZ(Counting of Leading Zero)最下位ビットから連続する0の数を求める */
#define clz(n) __builtin_clz(n)	    /* unsigned int */
#define clzl(n) __builtin_clzl(n)1  /* unsigned long */
#define clzll(n) __builtin_clzll(n) /* unsigned long long */
