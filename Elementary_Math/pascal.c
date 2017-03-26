int pascal(int n,int k)
{
    if(k==0||n==k)
      return 1;
    return pascal(n-1,k-1)+pascal(n-1,k);
}
