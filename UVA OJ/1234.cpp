#include <bits/stdc++.h>
#define ii pair<int,int>
#define pip pair<int,ii>
#define st first
#define nd second
using namespace std;

vector<pip> arestas;

int main(void)
{
  int tc;
  while(true)
  {
    scanf("%d",&tc);
    if(tc == 0) break;

    for(int i = 0;i < tc;i++)
    {
      int n,m;
      scanf("%d %d",&n,&m);

      for(int j = 0;j < m;j++)
      {
          int u,v,c;
          scanf("%d %d %d",&u,&v,&c);
          ii aresta = make_pair(u,v);
          arestas.push_back(make_pair(c,aresta));
      }
    }
  }



  return 0;
}
