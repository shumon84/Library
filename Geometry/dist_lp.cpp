// 直線aと点bとの距離
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
Real acrsb(Point a,Point b); // ベクトルa,bの外積

Real dist_lp(Line a,Point b)
{
  return abs(acrsb(a[1]-a[0],b-a[0]))/abs(a[1]-a[0]);
}
