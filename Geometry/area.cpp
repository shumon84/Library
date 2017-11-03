// ポリゴンの面積を求める
#include<complex>
#include<vector>
using namespace std;
typedef double Real;
typedef complex<Real> Point;
typedef vector<Point> Polygon;
Real acrsb(Point a,Point b);

Real area(Polygon p)
{
  Real a=0;
  int i;
  for(i=0;i<(int)p.size();i++)
    a+=acrsb(p[i],p[(i+1)%(int)p.size()]);
  return a/2;
}
