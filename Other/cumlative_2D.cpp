// 使い方
//   a,sの型はvector<vector<T>>とする
//   sum(s,i,j,h,w)
//   or
//   sum(Imos2D(a),i,j,h,w)
//
//   a[i  ,j  ] . . . a[i+h,j  ]
//        .              .
//        .              .        <-この矩形領域の和を求める
//        .              .
//   a[i  ,j+w] . . . a[i+h,j+w]
//
// 計算量
//   Imos2D() -> O(hw)
//   sum()    -> O(1)

#include<vector>
int i,j;
#define rep(i,n) for(i=0;i<n;i++)

template <class T>
std::vector<std::vector<T> > Imos2D(const std::vector<std::vector<T> >& a) {
    int h = a.size(), w = a[0].size();
    std::vector<std::vector<T> > s(h + 1, std::vector<T>(w + 1, 0));
    rep(i, h) rep(j, w) s[i + 1][j + 1] = a[i][j];
    rep(i, h + 1) rep(j, w) s[i][j + 1] += s[i][j];
    rep(i, h) rep(j, w + 1) s[i + 1][j] += s[i][j];
    return s;
}

template <class T>
int sum(const std::vector<std::vector<T> >& s, int i, int j, int h, int w) {
    return s[i + h][j + w] - s[i][j + w] + s[i][j] - s[i + h][j];
}
