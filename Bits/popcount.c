/* bitがいくつ立っているか返す */

/* 関数実装 */
int popcount(unsigned n)
{
  n=(0x55555555&n)+((0xaaaaaaaa&n)>>1);
  n=(0x33333333&n)+((0xcccccccc&n)>>2);
  n=(0x0f0f0f0f&n)+((0xf0f0f0f0&n)>>4);
  n=(0x00ff00ff&n)+((0xff00ff00&n)>>8);
  n=(0x0000ffff&n)+((0xffff0000&n)>>16);
  return n;
}

/* マクロ実装 */
#define popcount(n) (0x0000ffff&((0x00ff00ff&((0x0f0f0f0f&((0x33333333&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))+((0xcccccccc&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))>>2)))+((0xf0f0f0f0&((0x33333333&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))+((0xcccccccc&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))>>2)))>>4)))+((0xff00ff00&((0x0f0f0f0f&((0x33333333&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))+((0xcccccccc&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))>>2)))+((0xf0f0f0f0&((0x33333333&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))+((0xcccccccc&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))>>2)))>>4)))>>8)))+((0xffff0000&((0x00ff00ff&((0x0f0f0f0f&((0x33333333&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))+((0xcccccccc&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))>>2)))+((0xf0f0f0f0&((0x33333333&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))+((0xcccccccc&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))>>2)))>>4)))+((0xff00ff00&((0x0f0f0f0f&((0x33333333&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))+((0xcccccccc&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))>>2)))+((0xf0f0f0f0&((0x33333333&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))+((0xcccccccc&((0x55555555&(n))+((0xaaaaaaaa&(n))>>1)))>>2)))>>4)))>>8)))>>16)

/* gccのビルトイン関数 */
#define popcount(n) __builtin_popcount(n)     /* unsigned */
#define popcountl(n) __builtin_popcountl(n)   /* long */
#define popcountll(n) __builtin_popcountll(n) /* long long */
