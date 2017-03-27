// 点pから直線aに垂線を下ろした足
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
Real adotb(Point a,Point b);
Real length(Point a);
Point projection(Point p,struct Line a)
{
  Real t=adotb(p-a[0],a[0]-a[1])/length(a[0]-a[1]);
  return a[0]+t*(a[0]-a[1]);
}
