#include <bits/stdc++.h>
#define MAXN 106
using namespace std;

int l,c;
char grid[MAXN][MAXN];
int vis[MAXN][MAXN];
bool oleo = true;
vector<int> la[MAXN];

void limpa()
{
  for(int i = 0;i < MAXN;i++)
  {
    for(int j = 0;j < MAXN;j++)
    {
      vis[i][j] = 0;
    }
  }
}

void dfs(int i,int j)
{
  vis[i][j] = 1;


  //printf("i = %d j = %d\n",i,j);

  if(i-1 >= 0 && i-1 < l && j >= 0 && j < c)
  {
    if(!vis[i-1][j] && grid[i-1][j] != '*') dfs(i-1,j);
  }

  if(i >= 0 && i < l && j-1 >= 0 && j-1 < c)
  {
    if(!vis[i][j-1] && grid[i][j-1] != '*') dfs(i,j-1);
  }

  if(i+1 >= 0 && i+1 < l && j >= 0 && j < c)
  {
    if(!vis[i+1][j] && grid[i+1][j] != '*') dfs(i+1,j);
  }

  if(i >= 0 && i < l && j+1 >= 0 && j+1 < c)
  {
    if(!vis[i][j+1] && grid[i][j+1] != '*') dfs(i,j+1);
  }

  if(i+1 >= 0 && i+1 < l && j+1 >= 0 && j+1 < c)
  {
    if(!vis[i+1][j+1] && grid[i+1][j+1] != '*') dfs(i+1,j+1);
  }

  if(i-1 >= 0 && i-1 < l && j-1 >= 0 && j-1 < c)
  {
    if(!vis[i-1][j-1] && grid[i-1][j-1] != '*') dfs(i-1,j-1);
  }

  if(i+1 >= 0 && i+1 < l && j-1 >= 0 && j-1 < c)
  {
    if(!vis[i+1][j-1] && grid[i+1][j-1] != '*') dfs(i+1,j-1);
  }

  if(i-1 >= 0 && i-1 < l && j+1 >= 0 && j+1 < c)
  {
    if(!vis[i-1][j+1] && grid[i-1][j+1] != '*') dfs(i-1,j+1);
  }

}

int dfsVisit()
{
  int cc = 0;

  for(int i = 0;i < l;i++)
  {
    for(int j = 0;j < c;j++)
    {
      if(!vis[i][j] && grid[i][j] == '@')
      {
        oleo = true;
        dfs(i,j);
        //printf("\n\n");
        if(oleo == true)  cc++;
      }
    }
  }

  return cc;
}

int main(void)
{
  while(true)
  {
    string str;

    scanf("%d %d",&l,&c);
    if(l == 0 && c == 0) break;

    getchar();

    limpa();

    for(int i = 0;i < l;i++)
    {
      getline(cin,str);

      for(int j = 0;j < (int)str.length();j++)
      {
        grid[i][j] = str[j];
      }
    }

    int cc = dfsVisit();

    oleo == true ? printf("%d\n",cc) : printf("0\n");

  }

  return 0;
}
