// 二部グラフ判定
#include<vector>
using namespace std;
#define MAX_V 112345
vector<int> G[MAX_V];
int V;
int color[MAX_V];

bool dfs(int v,int c)
{
  color[v]=c;
  int i;
  for(i=0;i<G[v].size();i++)
    {
      if(color[G[v][i]]==c)return false;
      if(color[G[v][i]]==0&&!dfs(G[v][i],-c))return false;
    }
  return true;
}

bool is_bipartite()
{
  int i;
  for(i=0;i<V;i++)
    if(color[i]==0)
      if(!dfs(i,1))
	return false;
  
  return true;
}
