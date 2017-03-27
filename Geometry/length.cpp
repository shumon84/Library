// ベクトルaの長さ、点aの原点からの距離を求める。
#include<complex>
using namespace std;
typedef double Real;
typedef complex<Real> Point;
Real length(Point a)
{
  return abs(a);
}
