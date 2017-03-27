// ベクトルa,bの外積を求める。a x b = |a||b|sin()
#include<complex>
using namespace std;
typedef double Real;
typedef complex<Real> Point;
#define X(r) real(r)
#define Y(r) imag(r)

Real acrsb(Point a,Point b)
{
  return a.X()*b.Y()-a.Y()*b.X();
}
