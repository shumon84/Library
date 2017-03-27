// ベクトルaの単位ベクトルを求める
#include<complex>
using namespace std;
typedef double Real;
typedef complex<Real> Point;

Point unit(Point a)
{
  return a/abs(a);
}
