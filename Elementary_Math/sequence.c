/* 数列計算のライブラリ */


/* 等差数列*/
    /* 初項aと公差dから第n項を求める */
    #define art_gen(n,a,d) ((a)+(((n)-1))*(d)))

    /* 初項aと公差dから第n項までの総和を求める */
    #define art_sum1(n,a,d) ((2*(a)+((n)-1)*(d))/2)

    /* 初項aと末項bから第n項までの総和を求める */
    #define art_sum2(n,a,b) ((n)*((a)+(b))/2)


/* 等比数列*/
    /* 初項aと公比rから第n項を求める */
    int gmt_gen(int n,int a,int r)
    {
      int i;
      for(i=1;i<n;i++)
	a*=r;
      return a;
    }

    /* 初項aと公比rから第n項までの総和を求める */
    int gmt_sum1(int n,int a,int r)
    {
      int i;
      int rn;
      if(r==1)
	return n*a;

      for(i=0;i<n;i++)
	rn*=r;

      return a*(rn-1)/(r-1);
    }

/* シグマの展開公式 */

inline int sigma_k0(int _n,int _k0);
inline int sigma_k1(int _n,int _k1,int _k0);
inline int sigma_k2(int _n,int _k2,int _k1,int _k0);
inline int sigma_k3(int _n,int _k3,int _k2,int _k1,int _k0);

inline int sigma_k0(int _n,int _k0)
{
return ((_k0)*(_n))
}

inline int sigma_k1(int _n,int _k1,int _k0)
{
  return ((_k1)*((_n)*((_n)+1)/2)+sigma_k0(_n,_k0));
}

inline int sigma_k2(int _n,int _k2,int _k1,int _k0)
{
  return ((_k2)*((_n)*(_n+1)*(2*n+1)/6)+sigma_k1(_n,_k1,_k0));
}

inline int sigma_k3(int _n,int _k3,int _k2,int _k1,int _k0)
{
  return ((_k3)*(sigma_k1(_n,1))*(sigma_k1(_n,1))+sigma_k2(_n,_k2,_k1,_k0));
}
