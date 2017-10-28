#include <bits/stdc++.h>
#define MAXN 30050
using namespace std;

int mpes;
int vis;
vector<int> la[MAXN];
int pai[MAXN];
int visited[MAXN];

int dfsVisit(int u)
{
  visited[u] = 1;
  // printf("%d\n",u+1);
  for(int i = 0;i < la[u].size();i++)
  {
    int v = la[u][i];
    if(!visited[v])
    {
      vis++;
      pai[v] = u;
      dfsVisit(v);
    }
  }

  return vis;
}

void dfs(int n)
{
  for(int i = 0;i < n;i++)
  {
    if(!visited[i])
    {
      vis = 1;
      pai[i] = i;
      dfsVisit(i);
      mpes = max(mpes,vis);

      // printf("\n");
    }
  }
}

int main(void)
{
  int tc;
  scanf("%d",&tc);

  for(int i = 0;i < tc;i++)
  {
    int n,m;

    mpes = vis = 0;

    scanf("%d %d",&n,&m);

    for(int j = 0;j < n;j++)
    {
      la[j].clear();
      pai[j] = j;
      visited[j] = 0;
    }

    for(int j = 0;j < m;j++)
    {
      int u,v;
      scanf("%d %d",&u,&v);

      la[u-1].push_back(v-1);
      la[v-1].push_back(u-1);
    }
    // printf("caso %d\n",i+1);

    dfs(n);
    printf("%d\n",mpes);
  }


  return 0;
}
