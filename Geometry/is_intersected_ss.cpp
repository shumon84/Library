// 線分a,bの公差判定
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

int is_intersected_ss(Segment a,Segment b)
{
  return
    (acrsb(a[1]-a[0],b[0]-a[0])*acrsb(a[1]-a[0],b[1]-a[0])<EPS)&&
    (acrsb(b[1]-b[0],a[0]-b[0])*acrsb(b[1]-b[0],a[1]-b[0])<EPS);
}
