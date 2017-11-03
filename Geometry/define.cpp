#include<complex>
#include<vector>

using namespace std;

#define EPS (1e-10) //許容誤差。問題に合わせて変更。
#define DINF (1e+120) //十分大きな値
#define PI (3.14159265358979323846264338)

#define X(r) real(r)
#define Y(r) imag(r)
#define EQ(a,b) (abs((a)-(b))<EPS) // スカラーの等価判定
#define EQV(a,b) (EQ((a).X(),(b).X())&&EQ((a).Y(),(b).Y())) // ベクトルの等価判定

typedef double Real;		       // 実数
typedef complex<Real> Point;	       // 点・ベクトル
typedef vector<Point> Polygon;	       // 多角形(点の列)

// 直線 Line hoge(Point(a,b),Point(c,d)); 点(a,b),(c,d)を通る直線
struct Line : public vector<Point>
{
  Line(const Point &a, const Point &b)
  {
    push_back(a);
    push_back(b);
  }
};
// 線分 Segment hoge(Point(a,b),Point(c,d)); 点(a,b),(c,d)を端点に持つ線分
struct Segment : public vector<Point>
{
  Segment(const Point &a, const Point &b)
  {
    push_back(a);
    push_back(b);
  }
};
// 円 Circle hoge(Point(a,b),r); 中心(a,b)、半径rの円
struct Circle
{
  Point c;
  Real r;
  Circle(const Point &c,Real r):c(c),r(r){}
};

namespace std
{
  bool operator < (const Point& a, const Point& b)
  {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
  bool operator <= (const Point& a, const Point& b)
  {
    return real(a) != real(b) ? real(a) <= real(b) : imag(a) <= imag(b);
  }
  bool operator > (const Point& a, const Point& b)
  {
    return real(a) != real(b) ? real(a) > real(b) : imag(a) > imag(b);
  }
  bool operator >= (const Point& a, const Point& b)
  {
    return real(a) != real(b) ? real(a) >= real(b) : imag(a) >= imag(b);
  }
  bool operator == (const Point& a, const Point& b)
  {
    return a.real()==b.real()&&a.imag()==b.imag();
  }
  bool operator != (const Point& a, const Point& b)
  {
    return a.real()!=b.real()&&a.imag()!=b.imag();
  }
}
