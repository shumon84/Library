// 直線a,bの交点を求める
#include<complex>
#include<vector>
using namespace std;
typedef double Real;
typedef complex<Real> Point;
struct Line : public vector<Point>
{
  Line(const Point &a, const Point &b)
  {
   push_back(a); push_back(b);
  }
};
Real acrsb(Point a,Point b);

Point intersection_ll(struct Line a,struct Line b)
{
  Point A=a[1]-a[0];
  Point B=b[1]-b[0];
  return a[0]+A*acrsb(B,b[0]-a[0])/acrsb(B,A);
}
