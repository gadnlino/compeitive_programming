#include <bits/stdc++.h>
#define MAXN 50100
using namespace std;

vector<int> la[MAXN];
int dist[MAXN];
int vis[MAXN];
int pai[MAXN];

int bfs(int r,int k)
{
  int qt = 0;

  vis[r] = 1;
  dist[r] = 0;

  queue<int> fila;
  fila.push(r);

  while(!fila.empty())
  {
    int u = fila.front();
    fila.pop();
    // printf("%d -> dist = %d\n",u+1,dist[u]);
    if(dist[u] > k) break;

    if(dist[u] == k)
    {
      // printf("dist = %d\n",k);
      qt++;
    }

    for(int i = 0;i < (int) la[u].size();i++)
    {
      int v = la[u][i];
      if(!vis[v])
      {
        vis[v] = 1;
        pai[v] = u;
        dist[v] = dist[u] + 1;
        fila.push(v);
      }
    }
  }

  return qt;
}

void init()
{
  for(int i = 0;i < MAXN;i++)
  {
    dist[i] = 0;
    pai[i] = i;
    vis[i] = 0;
  }
}

int main()
{
  int n,k;
  cin >> n >> k;

  for(int i = 0;i < n-1;i++)
  {
    int u,v;
    scanf("%d %d",&u,&v);
    la[u-1].push_back(v-1);
    la[v-1].push_back(u-1);
  }

  int qt = 0;

  for(int i = 0;i < n;i++)
  {
    // printf("raiz %d\n",i+1);
    init();
    qt += bfs(i,k);
  }

  printf("%d\n",qt/2);

  return 0;
}
