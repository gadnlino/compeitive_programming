#include <bits/stdc++.h>
#define MAXN 1028
using namespace std;

char mat[MAXN][MAXN];
int vis[MAXN][MAXN];
int a,l;

void dfsVisit(int x,int y)
{
  vis[x][y] = 1;
  // cout << x << " " << y << endl;

  if(x-1 >= 0 && x-1 < a && y >= 0 && y < l)
  {
    // printf("indo para %d %d\n",x-1,y);
    if(!vis[x-1][y] && mat[x-1][y] != 'o')
      dfsVisit(x-1,y);
  }

  if(x >= 0 && x < a && y+1 >= 0 && y+1 < l)
  {
    // printf("indo para %d %d\n",x,y+1);
    if(!vis[x][y+1] && mat[x][y+1] != 'o')
      dfsVisit(x,y+1);
  }

  if(x+1 >= 0 && x+1 < a && y >= 0 && y < l)
  {
    // printf("indo para %d %d\n",x+1,y);
    if(!vis[x+1][y] && mat[x+1][y] != 'o')
      dfsVisit(x+1,y);
  }

  if(x >= 0 && x < a && y-1 >= 0 && y-1 < l)
  {
    // printf("indo para %d %d\n",x,y-1);
    if(!vis[x][y-1] && mat[x][y-1] != 'o')
      dfsVisit(x,y-1);
  }
  // cout << "r" << endl;
}

int dfs(int a,int l)
{
  int reg = 0;

  for(int i = 0;i < a;i++)
  {
    for(int j = 0;j < l;j++)
    {
      if(!vis[i][j] && mat[i][j] != 'o')
      {
        // printf("raiz %d %d\n",i,j);
        dfsVisit(i,j);
        reg++;
        // printf("\n");
      }
    }
  }

  return reg;
}

int main()
{
  cin >> a >> l;

  for(int i = 0;i < a;i++)
  {
    for(int j = 0;j < l;j++)
    {
      cin >> mat[i][j];
    }
  }

  // for(int i = 0;i < a;i++)
  // {
  //   for(int j = 0;j < l;j++)
  //   {
  //     cout << mat[i][j];
  //   }
  //   cout << endl;
  // }


  int reg = dfs(a,l);

  printf("%d\n",reg);

  return 0;
}
