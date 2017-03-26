#include<complex>
#include<vector>

using namespace std;

#define EPS (1e-10) //許容誤差。問題に合わせて変更。

#define X real()
#define Y imag()

#define EQ(a,b) (abs((a)-(b)) < EPS) // スカラーの等価判定
#define EQV(a,b) (EQ((a).X,(b).X)&&EQ((a).Y,(b).Y)) // ベクトルの等価判定

typedef double Real;		       // 実数
typedef complex<Real> Point;	       // 点・ベクトル
typedef vector<Point> Polygon;	       // 多角形(点の列)

// 直線
struct Line : public vector<Point>
{
  Line(const Point &a, const Point &b)
  {
   push_back(a); push_back(b);
  }
};
// 線分
struct Segment : public vector<Point>
{
  Segment(const Point &a, const Point &b)
  {
   push_back(a); push_back(b);
  }
};
// 円 Circle hoge(Point(a,b)); 中心(a,b)、半径rの円になる。
struct Circle
{
  Point c;
  double r;
  Circle(const Point &c,double r):c(c),r(r){}
};


namespace std
{
  bool operator < (const Point& a, const Point& b)
  {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
  bool operator == (const Point& a, const Point& b)
  {
    return a.real()==b.real()&&a.imag()==b.imag();
  }
}

int main()
{
}
