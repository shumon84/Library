#define LCS_MAX_N //文字列sの最大文字数
#define LCS_MAX_M //文字列tの最大文字数

int lcs(char s[],char t[],int n,int m)
{
  int i,j;
  int dp[LCS_MAX_N+1][LCS_MAX_M+1]={};
  for(i=0;i<n;i++)
    for(j=0;j<m;j++)
      if(s[i]==t[j])
	dp[i+1][j+1]=dp[i][j]+1;
      else
	dp[i+1][j+1]=(dp[i][j+1]>dp[i+1][j])?dp[i][j+1]:dp[i+1][j];
  return dp[n][m];
}
