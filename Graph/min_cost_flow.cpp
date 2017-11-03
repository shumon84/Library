// 最小費用流
#include<vector>
#include<cstring>

using namespace std;

#define INF 0x7fffffff
#define MAX_V 112345

struct edge
{
  int to;
  int cap;
  int cost;
  int rev;
};

int V; // 頂点数
vector<edge> G[MAX_V]; // グラフの隣接リスト表現
int d[MAX_V]; // 最短距離
int prevv[MAX_V],preve[MAX_V]; // 直前の頂点と辺

// fromからtoへの容量capの辺を追加する 
void add_edge(int from,int to,int cap,int cost)
{
  G[from].push_back((edge){to,cap,cost,(int)G[to].size()});
  G[to].push_back((edge){from,0,-cost,(int)G[from].size()-1});
}

// sからtへの流量fの最小費用流を求める(流せない場合は-1)
int min_cost_flow(int s,int t,int f)
{
  int res=0;
  while(f>0)
    {
      fill(d,d+V,INF);
      d[s]=0;
      bool update=true;
      while(update)
	{
	  update=false;
	  for(int v=0;v<V;v++)
	    {
	      if(d[v]==INF)
		continue;
	      for(int i=0;i<(int)G[v].size();i++)
		{
		  edge &e=G[v][i];
		  if(e.cap>0&&d[e.to]>d[v]+e.cost)
		    {
		      d[e.to]=d[v]+e.cost;
		      prevv[e.to]=v;
		      preve[e.to]=i;
		      update=true;
		    }
		}
	    }
	}
      if(d[t]==INF)
	return -1;
      
      int dc=f;
      for(int v=t;v!=s;v=prevv[v])
	dc=min(dc,G[prevv[v]][preve[v]].cap);

      f-=dc;
      res+=dc*d[t];

      for(int v=t;v!=s;v=prevv[v])
	{
	  edge &e=G[prevv[v]][preve[v]];
	  e.cap-=dc;
	  G[v][e.rev].cap+=dc;
	}
    }
  return res;
}
