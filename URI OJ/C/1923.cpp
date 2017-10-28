#include <bits/stdc++.h>
#define MAXN 1003
using namespace std;

vector<int> la[MAXN];
int dst[MAXN],mrc[MAXN];
set<int> bfs(int,int);
map<string,int> mapa;


int main()
{
  int rel,qt;
  scanf("%d %d",&rel,&qt);
  int cont = 0;

  for(int i = 0;i < rel;i++)
  {
    string nome1,nome2;
    cin >> nome1 >> nome2;

    if(mapa.find(nome1) == mapa.end())
    {
      mapa.insert(make_pair(nome1,cont++));
    }

    if(mapa.find(nome2) == mapa.end())
    {
      mapa.insert(make_pair(nome2,cont++));
    }

    la[mapa[nome1]].push_back(mapa[nome2]);
    la[mapa[nome2]].push_back(mapa[nome1]);
  }

  set<int> fim = bfs(mapa["Rerisson"],qt);

  cout << fim.size() << endl;

  map<string,int>::iterator it;

  for(it = mapa.begin();it != mapa.end();it++)
  {
    pair<string,int> par = *it;
    if(fim.find(par.second) != fim.end())
    {
      cout << par.first << endl;
    }
  }

  return 0;
}


set<int> bfs(int root,int qt)
{
  set<int> bag;

  mrc[root] = 1;
  dst[root] = 0;

  queue<int> fila;

  fila.push(root);


  while(!fila.empty())
  {
    int u = fila.front();
    fila.pop();

    for(int i = 0;i < (int)la[u].size();i++)
    {
      int f = la[u][i];
      //printf("%d\n",f);
      if(!mrc[f])
      {
        mrc[f] = 1;
        dst[f] = dst[u] + 1;
        fila.push(f);
        if(dst[f] <= qt)
        {
          bag.insert(f);
          //bag.push_back(f);
        }
      }
    }
  }

  return bag;
}
