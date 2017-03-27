// 点pを直線aで折り返した点
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
Point projection(Point p,struct Line a);
Point reflection(Point p,struct Line a)
{
  return p+2.0*(projection(p,a)-p);
}
