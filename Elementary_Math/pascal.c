/* パスカルの三角形(二項定理) */
#define PASCAL_N 1000
#define PASCAL_K 1000
long long ps[PASCAL_N][PASCAL_K];
long long  pascal(int n,int k)
{
  if(ps[n][k]==0)
    {
      if(k==0||n==k)
	return ps[n][k]=1;
      return ps[n][k]=ps[n-1][k-1]+ps[n-1][k];
    }
  else
    return ps[n][k];
}
