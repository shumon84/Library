// 点cが直線a,b上にあるかないか
#include<complex>
#include<vector>
using namespace std;
#define EPS (1e-10)
#define EQ(a,b) (abs((a)-(b))<EPS)
typedef double Real;
typedef complex<Real> Point;
struct Line : public vector<Point>
{
  Line(const Point &a, const Point &b)
  {
   push_back(a); push_back(b);
  }
};
Real acrsb(Point a,Point b); //ベクトルa,bの外積

int is_point_on_line(struct Line a,Point b)
{
  return EQ(acrsb(a[1]-a[0],b-a[0]),0.0);
}
