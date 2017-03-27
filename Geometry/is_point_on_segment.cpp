// 点cが線分a,b上にあるかないか
#include<complex>
#include<vector>
using namespace std;
#define EPS (1e-10)
#define EQ(a,b) (abs((a)-(b))<EPS)
typedef double Real;
typedef complex<Real> Point;
struct Segment : public vector<Point>
{
  Segment(const Point &a, const Point &b)
  {
   push_back(a); push_back(b);
  }
};
Real acrsb(Point a,Point b); //ベクトルa,bの外積
Real adotb(Point a,Point b); //ベクトルa,bの内積

int is_point_on_segment(struct Segment a,Point b)
{
  return (abs(a[0]-b)+abs(b-a[1])<abs(a[0]-b)+EPS);
}
