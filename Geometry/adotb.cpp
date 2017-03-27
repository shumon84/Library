// ベクトルa,bの内積を求める。a・b = |a||b|cos()
#include<complex>
using namespace std;
typedef double Real;
typedef complex<Real> Point;
#define X(r) real(r)
#define Y(r) imag(r)

Real adotb(Point a,Point b)
{
  return (a.X()*b.X()+a.Y()*b.Y());
}
