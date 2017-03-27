// ベクトルaの法線ベクトルを求める。
#include<complex>
using namespace std;
typedef double Real;
typedef complex<Real> Point;

Point normal(Point a,int select)
{
  if(select)
    return a*Point(0,1);
  else
    return a*Point(0,-1);
}
