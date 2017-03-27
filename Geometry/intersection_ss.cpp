// 線分a,bの交点を求める
#include<complex>
#include<vector>
using namespace std;
typedef double Real;
typedef complex<Real> Point;
struct Segment : public vector<Point>
{
  Segment(const Point &a, const Point &b)
  {
   push_back(a); push_back(b);
  }
};
#define EPS (1e-10)
Real acrsb(Point a,Point b);

Point intersection_ss(struct Segment a,struct Segment b)
{
  Point p=b[1]-b[0];
  Real d1=abs(acrsb(p,a[0]-b[0]));
  Real d2=abs(acrsb(p,a[1]-b[0]));
  Real t=d1/(d1+d2);
  return a[0]+(a[1]-a[0])*t;
}
