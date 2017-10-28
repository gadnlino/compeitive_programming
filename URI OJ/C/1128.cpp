#include <bits/stdc++.h>
#define MAXN 1000
#define GQTD 2
using namespace std;

vector<int> la[GQTD][MAXN];
int mrc[GQTD][MAXN];

void init();
void bfs(int);
vector<int> traverse(int,int);

int main(void)
{
  int v,e;
  while(1)
  {
    cin >> v >> e;
    if(v == 0 && e == 0) break;
    init();

    for(int i = 0;i < e;i++)
    {
      int a,b,m;
      cin >> a >> b >> m;

      if(m == 1)
      {
        la[0][a-1].push_back(b-1);
        la[1][b-1].push_back(a-1);
      }
      if(m == 2)
      {
        la[0][a-1].push_back(b-1);
        la[1][b-1].push_back(a-1);
        la[0][b-1].push_back(a-1);
        la[1][a-1].push_back(b-1);
      }
    }
    /*
    for(int i = 0;i < GQTD;i++)
    {
      printf("Grafo %d\n\n",i + 1);
      for(int j = 0;j < v;j++)
      {
        printf("%d ->\t",j+1);
        for(int k = 0;k < la[i][j].size();k++)
        {
          k < la[i][j].size() - 1 ? printf("%d ",la[i][j][k]+1) : printf("%d",la[i][j][k]+1);
        }
        printf("\n");
      }

      cout << endl;
    }
    */

    bfs(v);


    for(int i =0;i < GQTD;i++)
    {
      for(int j = 0;j < MAXN;j++)
      {
        la[i][j].clear();
      }
    }
  }

  return 0;
}


void bfs(int v)
{
  vector<vector<int> > scc[GQTD];

  for(int i = 0;i < GQTD;i++)
  {
    for(int j = 0;j < v;j++)
    {
      vector<int> l1;
      /*
      for(int y = 0;y < GQTD;y++)
      {
        for(int r = 0;r < v;r++)
        {
          r < v-1 ? printf("%d ",mrc[y][r]) : printf("%d\n",mrc[y][r]);
        }
      }
      cout << endl;
      */

      if(!mrc[i][j])
      {
        l1 = traverse(i,j);
      }

      if(!l1.empty()) scc[i].push_back(l1);
    }
  }

  //printf("%d --- %d\n",(int)scc[0].size(),(int)scc[1].size());

  /*
  for(int k = 0;k < GQTD;k++)
  {
    for(int i = 0;i < (int)scc[k].size();i++)
    {
      for(int j = 0;j < (int)scc[k][i].size();j++)
      {
        j < (int)scc[k][i].size() - 1 ? printf("%d ",scc[k][i][j]+1) : printf("%d\n",scc[k][i][j]+1);
      }
    }
  }
  */
  if((int)scc[0].size() == (int)scc[1].size() && (int)scc[0].size() == 1){
    printf("1\n");
  }
  else printf("0\n");

}


vector<int> traverse(int grafo,int src)
{

  vector<int> vet;

  if(!mrc[grafo][src]) vet.push_back(src);

  //printf("traversing graph %d,src = %d\n\n",grafo + 1,src+1);
  mrc[grafo][src] = 1;

  queue<int> fila;
  fila.push(src);

  while(!fila.empty())
  {
    int u = fila.front();
    fila.pop();

    for(int i = 0;i < (int)la[grafo][u].size();i++)
    {
      int v = la[grafo][u][i];
      if(!mrc[grafo][v])
      {
        mrc[grafo][v] = 1;
        fila.push(v);
        vet.push_back(v);
      }
    }
  }
  /*
  for(int i = 0;i < (int)vet.size();i++)
  {
    i < (int)vet.size()-1 ? printf("%d ",vet[i]+1) : printf("%d\n\n",vet[i]+1);
  }
  */
  return vet;
}


void init()
{
  for(int i = 0;i < GQTD;i++)
  {
    for(int j = 0;j < MAXN;j++)
    {
      mrc[i][j] = 0;
    }
  }
}
