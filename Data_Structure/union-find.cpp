#include <iostream>
#include <vector>

class union_find
{
  std::vector<size_t> parent;
  std::vector<size_t> rank;

public:
  // 初期化
  union_find(size_t size)
  {
    parent.resize(size);
    rank.resize(size);
    for(size_t i=0;i<size;i++)
      {
        parent[i]=i;
        rank[i]=1;
      }
  }

  // aとbをグルーピング
  void unite(size_t a,size_t b)
  {
    a=find(a);
    b=find(b);
    if(a==b)
      return;
    if(rank[a]<rank[b])
      parent[a]=b;
    else
      parent[b]=a;
    if(rank[a]==rank[b])
      rank[a]++;
  }

  size_t find(size_t node)
  {
    if(parent[node]==node)
      return node;
    else
      return parent[node]=find(parent[node]);
  }

  bool same(size_t a, size_t b)
  {
    return find(a)==find(b);
  }
};
