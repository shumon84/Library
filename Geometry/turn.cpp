// ベクトルaをt度反時計回りに回転する
#include<complex>
#include<vector>
using namespace std;
typedef double Real;
typedef complex<Real> Point;
#define PI (3.14159265358979323846264338)

Point turn(Point a,double t)
{
  return a*exp(Point(0.0,t*PI/180.0));
}
