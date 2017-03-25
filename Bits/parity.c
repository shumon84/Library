/* popcount(n)%2を求める。包除原理の加減判定に用いる */
#define parity(n) __builtin_parity(n)     /* unsigned int */
#define parityl(n) __builtin_parityl(n)	  /* unsigned long */
#define parityll(n) __builtin_parityll(n) /* unsigned long long */
