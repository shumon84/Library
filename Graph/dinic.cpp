#include<vector>
#include<queue>
#include<cstring>

using namespace std;

#define INF 0x7fffffff
#define MAX_V 112345

struct edge
{
  int to;
  int cap;
  int rev;
};

vector<edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];

// fromからtoへの容量capの辺を追加する
void add_edge(int from,int to,int cap)
{
  G[from].push_back((edge){to,cap,(int)G[to].size()});
  G[to].push_back((edge){from,0,(int)G[from].size()});
}

void bfs(int s)
{
  memset(level,-1,sizeof(level));
  queue<int> que;
  level[s]=0;
  que.push(s);
  while(!que.empty())
    {
      int v=que.front();
      que.pop();
      for(int i=0;i<(int)G[v].size();i++)
	{
	  edge &e=G[v][i];
	  if(e.cap>0&&level[e.to]<0)
	    {
	      level[e.to]=level[v]+1;
	      que.push(e.to);
	    }
	}
    }
}
  
int dfs(int v,int t,int f)
{
  if(v==t) return f;
  for(int &i=iter[v];i<(int)G[v].size();i++)
    {
      edge &e=G[v][i];
      if(e.cap>0&&level[v]<level[e.to])
	{
	  int d=dfs(e.to,t,min(f,e.cap));
	  if(d>0)
	    {
	      e.cap-=d;
	      G[e.to][e.rev].cap+=d;
	      return d;
	    }
	}
    }
  return 0;
}

// sからtへの最大流を求める
int dinic(int s,int t)
{
  int flow=0;
  for(;;)
    {
      bfs(s);
      if(level[t]<0)
	return flow;
      memset(iter,0,sizeof(iter));
      int f;
      while((f=dfs(s,t,INF))>0)
	flow+=f;
    }
}
