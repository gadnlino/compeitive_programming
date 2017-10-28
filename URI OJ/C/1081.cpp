#include <bits/stdc++.h>
#define MAXN 33
using namespace std;

void dfs(int);
void dfsVisit(int,int);

vector<int> la[MAXN];
int pai[MAXN];
int vis[MAXN];
int visitados;

int main(void)
{
  int tc;
  scanf("%d",&tc);

  for(int i = 0;i < tc;i++)
  {
    printf("Caso %d:\n",i+1);

    int n,m;
    scanf("%d %d",&n,&m);
    visitados = 0;
    for(int j = 0;j < n;j++)
    {
      la[j].clear();
      pai[j] = j;
      vis[j] = 0;
    }

    for(int j = 0;j < m;j++)
    {
      int u,v;
      scanf("%d %d",&u,&v);
      la[u].push_back(v);
      //la[v].push_back(u);
    }

    dfs(n);
  }

  //printf("\n");

  return 0;
}

void dfs(int n)
{

  for(int i = 0;i < n;i++)
  {
    int visAtual = visitados;
    if(!vis[i])
    {
      pai[i] = i;
      dfsVisit(i,1);
      if(visitados != visAtual+1) printf("\n");
    }
  }
}

void dfsVisit(int u,int lvl)
{
  vis[u] = 1;
  visitados++;
  sort(la[u].begin(),la[u].end());
  for(int i = 0;i < la[u].size();i++)
  {
    int v = la[u][i];

    if(!vis[v])
    {
      for(int k = 0;k < 2*lvl;k++) printf(" ");
      printf("%d-%d pathR(G,%d)\n",u,v,v);
      pai[v] = u;
      dfsVisit(v,lvl+1);
    }
    else
    {
      for(int k = 0;k < 2*lvl;k++) printf(" ");
      printf("%d-%d\n",u,v);
    }
  }

  //if(pai[u] == u) printf("\n");
}
