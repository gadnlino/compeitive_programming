#include <bits/stdc++.h>
#define MAXN 1000
#define INF 0X3F3F3F
using namespace std;

vector<int> la[MAXN];
int dist[MAXN];
int mark[MAXN];
int usado[MAXN];
int quantOver;

void bfs(int);
void limpa(void);
int confere(int,int);

int main(void)
{
  int contCasos = 0;

  while(true)
  {
    int edges;
    scanf("%d",&edges);

    if(!edges) break;

    map<long long int,int> mapa;
    int cont = 0;
    int n = 0;

    for(int i = 0;i < edges;i++)
    {
      long long int a,b;
      scanf("%lld %lld",&a,&b);

      /*
      for(int y = 0;y <= maior;y++)
      {
        if(mapa.find(y) == mapa.end())
        {
          mapa[y] = cont++;
        }
      }
      */

      if(mapa.find(a) != mapa.end())
      {
        int u = mapa[a];

        if(mapa.find(b) != mapa.end())
        {
          int v = mapa[b];
          la[u].push_back(v);
          la[v].push_back(u);
          //printf("achei a e achei b\n");
        }
        else
        {
          n++;
          mapa[b] = cont++;
          int v = mapa[b];
          la[u].push_back(v);
          la[v].push_back(u);
          //printf("achei a e nao achei b\n");
        }
      }
      else
      {
        mapa[a] = cont++;
        int u = mapa[a];

        n++;

        if(mapa.find(b) != mapa.end())
        {
          int v = mapa[b];
          la[u].push_back(v);
          la[v].push_back(u);
          //printf("nao achei a e achei b\n");
        }
        else
        {
          mapa[b] = cont++;
          int v = mapa[b];
          la[u].push_back(v);
          la[v].push_back(u);
          
          //printf("nao achei a e nao achei b\n");
        
          n++;
        }
      }
      
      usado[mapa[a]] = usado[mapa[b]] = 1;
      /*
      cout << "a" << " " << a << " " << mapa[a] << " // ";
      cout << "b" << " " << b << " " << mapa[b] << endl << endl;
      */
    }

    /*
    for(int i = 0;i < MAXN;i++)
    {
      if(usado[i])
      {
        printf("%d -> ",i);

        for(int j = 0;j < la[i].size();j++)
        {
          printf("%d ",la[i][j]);
        }
        printf("\n");
      }
    }
    printf("\n");
    */

    while(1)
    {
      long long int v;
      int ttl;
      scanf("%lld %d",&v,&ttl);

      if(!v && !ttl) break;

      quantOver = 0;
      limpa();
      
      if(mapa.find(v) == mapa.end())
      {
        quantOver = n;
      }
      else
      {
        bfs(mapa[v]);
        quantOver = confere(ttl,cont);
      }

      printf
      ("Case %d: %d nodes not reachable from node %lld with TTL = %d.\n",
      ++contCasos,quantOver,v,ttl);
      /*
      if(mapa.find(v) == mapa.end())
      {
        printf("oi\n");
        mapa[v] = cont++;
      }
      */
      /*
      int mapV = mapa[v];
      //printf("vq = %lld,map[vq] = %d\n",v,mapV);

      ii par = make_pair(mapV,ttl);
      pip par2 = make_pair(v,par);
      query.push_back(par2);
      */
    }

    //printf("vertices  = %d\n",n);
    /*
    for(int k = 0;k < (int)query.size();k++)
    {
      int vertex = query[k].first;
      int src = query[k].second.first;
      int ttl = query[k].second.second;

      quantOver = 0;
      limpa();



      if(mapa.find(vertex) == mapa.end())
      {
        //cout << "oi" << endl;
        quantOver = n;
      }
      else
      {
        bfs(src,ttl);

        quantOver = confere(ttl,cont);
        //printf("%d map = %d\n",vertex,src);
      }
      

      printf
      ("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",
      ++contCasos,quantOver,vertex,ttl);
    }
    */
    for(int i = 0;i < MAXN;i++)
    {
      la[i].clear();
    }
  }


  return 0;
}


void bfs(int src)
{
  dist[src] = 0;
  mark[src] = 1;

  queue<int> fila;
  fila.push(src);

  while(!fila.empty())
  {
    int u = fila.front();
    fila.pop();

    //if(dist[u] > ttl) quantOver++;

    //printf("u = %d,dist[u] = %d\n",u,dist[u]);

    for(int i = 0;i < (int)la[u].size();i++)
    {
      int v = la[u][i];

      if(!mark[v])
      {
        mark[v] = 1;
        dist[v] = dist[u] + 1;
        fila.push(v);
      }
    
      //printf("dist = %d\n",dist[v])
      
    }
  }
}


void limpa()
{
  for(int i = 0;i < MAXN;i++)
  {
    dist[i] = INF;
    mark[i] = 0;
  }
}


int confere(int ttl,int v)
{
  int cont = 0;

  for(int i = 0;i < v;i++)
  {
    if(dist[i] > ttl) cont++;
  }

  return cont;
}