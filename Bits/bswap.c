/* ビット列を逆転させる。反転とは違うので注意 */
#define bswap(n) __buitin_bswap(n)     /* unsigned int */
#define bswapl(n) __buitin_bswapl(n)   /* unsigned long */
#define bswapll(n) __buitin_bswapll(n) /* unsigned long long*/
