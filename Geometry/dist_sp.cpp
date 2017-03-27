// 線分aと点bとの距離
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
#define EQ(a,b) (abs((a)-(b))<EPS)
Real adotb(Point a,Point b);
Real acrsb(Point a,Point b);

Real dist_sp(struct Segment a,Point b) {
  if (adotb(a[1]-a[0], b-a[0])<EPS)return abs(b-a[0]);
  if (adotb(a[0]-a[1], b-a[1])<EPS)return abs(b-a[1]);
  return abs(acrsb(a[1]-a[0],b-a[0]))/abs(a[1]-a[0]);
}
