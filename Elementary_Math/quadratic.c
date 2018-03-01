/* 二次関数のライブラリ */

/* xy座標 */
typedef struct
{
  int x;
  int y;
}Dot;

/* 二次関数の係数 */
typedef struct
{
  int x2;
  int x1;
  int x0;
}SFunc;

/* 一次関数の係数 */
typedef struct
{
  int x1;
  int x0;
}LFunc;

/* 二次関数fxの頂点を求める */
Dot apex(SFunc fx)
{
  Dot p;
  int a=fx.x2;
  int b=fx.x1;
  int c=fx.x0;
  p.x=-b/2*a;
  p.y=-(b*b-4*a*c)/4*a;
  return p;
}

/* 二次関数fxの軸を求める */
int axis(SFunc fx)
{
  int a=fx.x2;
  int b=fx.x1;
  return -b/(2*a);
}

/* 判別式(正->交点2個 0->交点1個 負->交点0個)*/
int disc(SFunc fx)
{
  int a=fx.x2;
  int b=fx.x1;
  int c=fx.x0;
  return b*b-4*a*c;
}

/* 向き(下に凸or上に凸) 0->下に凸 1->上に凸*/
#define dirc(fx) fx.x2<0

/* 平行移動(fxをx軸の正の向きにx、y軸の正の向きにy移動)*/
SFunc p_disp(SFunc fx,int x,int y)
{
  int a=fx.x2;
  int b=fx.x1;
  int c=fx.x0;
  fx.x2=a;
  fx.x1=b-2*a*x;
  fx.x0=a*x*x-b*x+c+y;
  return fx;
}

/* 対称移動(二次関数fxをx軸に関して対称移動) */
SFunc lx_smtr(SFunc fx)
{
  int a=fx.x2;
  int b=fx.x1;
  int c=fx.x0;
  fx.x2=-a;
  fx.x1=-b;
  fx.x0=-c;
  return fx;
}

/* 対称移動(二次関数fxをy軸に関して対称移動) */
SFunc ly_smtr(SFunc fx)
{
  int a=fx.x2;
  int b=fx.x1;
  int c=fx.x0;
  fx.x2=a;
  fx.x1=-b;
  fx.x0=c;
  return fx;
}

/* 対称移動(二次関数fxをy=xに関して対称移動) */
SFunc lxy_smtr(SFunc fx)
{
  int a=fx.x2;
  int b=fx.x1;
  int c=fx.x0;
  fx.x2=-a;
  fx.x1=b;
  fx.x0=-c;
  return fx;
}
