// 2点a,b間の距離を求める
#include<complex>
using namespace std;
typedef double Real;
typedef complex<Real> Point;

Real dist_pp(Point a,Point b)
{
  return abs(a-b);
}
