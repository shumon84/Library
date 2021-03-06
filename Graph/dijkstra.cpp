#include<queue>
#include<vector>

using namespace std;

typedef pair<int,int> i_i;

#define INF 0x7fffffff

#define MAX_V 112345 //　頂点の数の最大

struct edge
{
  int to;
  int cost;
};

int V; // 頂点の数(忘れず代入する)
vector<edge> G[MAX_V]; // 辺集合
int d[MAX_V]; // 全点対単一視点最短経路長

void dijkstra(int s)
{
  int i;
  priority_queue<i_i,vector<i_i>,greater<i_i>> que;
  fill(d,d+V,INF);
  d[s]=0;
  que.push(i_i(0,s));
  while(!que.empty())
    {
      i_i p=que.top();
      que.pop();
      int v=p.second;
      if(d[v]<p.first) continue;
      int n=G[v].size();
      for(i=0;i<n;i++)
	{
	  edge e=G[v][i];
	  if(d[e.to]>d[v]+e.cost)
	    {
	      d[e.to]=d[v]+e.cost;
	      que.push(i_i(d[e.to],e.to));
	    }	  
	}
    }
}
