// エラトステネスの篩
#include<cmath>

#define NUM_OF_PRIME 1000

unsigned prime[NUM_OF_PRIME];
void eratosthenes(void)
{
  unsigned i, j;
  unsigned sq_num = (int)sqrt((double)NUM_OF_PRIME);

  // 1が立っているものが素数
  // 0が立っているものが合成数（素数ではない）

  for (i = 0; i < NUM_OF_PRIME; i++)
    prime[i] = 1;  // 全ての数に1を立てる
  prime[0] = 0;    // 1は素数ではない

  for (i = 1; i < sq_num; i++) {
    if (prime[i] == 1)          // prime[i]が素数なら
      for (j = (i+1); (i+1) * j <= NUM_OF_PRIME; j++)
        prime[(i+1) * j - 1] = 0;  // 素数の倍数は素数ではない
  }
}
