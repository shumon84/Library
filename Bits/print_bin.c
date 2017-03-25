void print_bin(int n)
{
  for(unsigned i=(1<<(sizeof(int)*8-1));i;i>>=1)
    putchar('0'+((n&i)?1:0));
  puts("");
}
