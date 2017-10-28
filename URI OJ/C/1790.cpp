#include <bits/stdc++.h>
#define MAXN 55
#define ii pair<int,int>
using namespace std;

vector<int> la[MAXN];
int vis[MAXN];
int pai[MAXN];
int dfs(int);
void dfsVisit(int);
void monta(queue<ii>);

int main(void)
{

  int n,m;
  while(scanf("%d %d",&n,&m) != EOF)
  {
    queue<ii> arestas;
    for(int i = 0;i < m;i++)
    {
      int u,v;
      scanf("%d %d",&u,&v);
      arestas.push(make_pair(u-1,v-1));
    }

    monta(arestas);

    int normal = dfs(n);
    int pontes = 0;

    for(int i = 0;i < m;i++)
    {
      ii e = arestas.front();
      arestas.pop();
      //printf("%d -- %d\n",e.first+1,e.second+1);
      monta(arestas);
      int comp = dfs(n);
      //printf("norm %d comp %d\n",normal,comp);
      if(comp > normal)
      {
        // printf("%d %d é ponte\n",e.first+1,e.second+1);
        pontes++;
      }
      arestas.push(e);
    }

    printf("%d\n",pontes);
  }


  return 0;
}

int dfs(int n)
{
  //printf("busca %d \n",n);
  int cconex = 0;
  for(int i = 0;i < n;i++)
  {
    if(!vis[i])
    {
      //printf("raiz %d\n",i+1);
      pai[i] = i;
      dfsVisit(i);
      cconex++;
      //printf("conexas++\n");
    }
  }

  return cconex;
}

void dfsVisit(int u)
{
  vis[u] = 1;

  for(int i = 0;i < (int)la[u].size();i++)
  {
    int v = la[u][i];
    if(!vis[v])
    {
      pai[v] = u;
      dfsVisit(v);
    }
  }
}

void monta(queue<ii> arestas)
{
  for(int i = 0;i < MAXN;i++)
  {
    vis[i] = 0;
    pai[i] = i;
    la[i].clear();
  }

  for(int i = 0;i < (int)arestas.size();i++)
  {
    ii e = arestas.front();
    arestas.pop();
    la[e.first].push_back(e.second);
    la[e.second].push_back(e.first);
    arestas.push(e);
  }

  /*
  for(int i = 0;i < 4;i++)
  {
    printf("%d ->",i+1);
    for(int j = 0;j < (int)la[i].size();j++)
    {
      printf("%d ",la[i][j]+1);
    }
    printf("\n");

  }*/
}
