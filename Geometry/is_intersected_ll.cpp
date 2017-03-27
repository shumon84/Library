// 直線aと直線bの交差判定
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
#define EPS (1e-10)
#define EQ(a,b) (abs((a)-(b))<EPS)
Real acrsb(Point a,Point b);

int is_intersected_ll(struct Line a,struct Line b)
{
  return !EQ(acrsb(a[0]-a[1],b[0]-b[1]),0.0);
}
