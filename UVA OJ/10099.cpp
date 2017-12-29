#include <bits/stdc++.h>
#define MAXN 103
#define ii pair<int,int>
#define pip pair<int,ii >
#define vip vector<pip>
#define st first
#define nd second

using namespace std;

vip arestas,caminhoDFS;
int pai[MAXN],tam[MAXN],mrc[MAXN],menor,peop;

vector<ii> ag[MAXN];

int find(int a)
{
  if(a == pai[a]) return a;

  return pai[a] = find(pai[a]);
}

void unir(int a,int b)
{
  a = find(a);
  b = find(b);

  if(tam[a] >= tam[b])
  {
    pai[b] = a;
    tam[a] += tam[b];
  }
  else
  {
    pai[a] = b;
    tam[b] += tam[a];
  }
}

void init(int n)
{
  for(int i = 0;i < n;i++)
  {
    pai[i] = i;
    tam[i] = 1;
    mrc[i] = 0;
    ag[i].clear();
  }

  arestas.clear();
  caminhoDFS.clear();
}

void monta(vip tree)
{
  for(int i = 0;i < (int)tree.size();i++)
  {
    int u = tree[i].nd.st;
    int v = tree[i].nd.nd;
    int p = tree[i].st;

    ag[u].push_back(make_pair(v,p));
    ag[v].push_back(make_pair(u,p));
  }
}

void dfs(int u,int dst,vip path)
{
  mrc[u] = 1;
  //printf("m = %d\n",menor);

  if(u == dst)
  {
    caminhoDFS = path;
    return;
  }

  for(int i = 0;i < (int)ag[u].size();i++)
  {
    int v = ag[u][i].st;
    int p = ag[u][i].nd;

    if(!mrc[v])
    {
      path.push_back(make_pair(p,make_pair(u,v)));
      dfs(v,dst,path);
      path.erase(path.begin() + path.size()-1);
    }
  }
}

int main(void)
{
  int n,m;
  int cont = 0;

  while(true)
  {
    scanf("%d %d",&n,&m );
    if(n == m && m == 0) break;

    init(n);

    for(int i = 0;i < m;i++)
    {
      int u,v,p;
      scanf("%d %d %d",&u,&v,&p);
      ii par = make_pair(u-1,v-1);
      pip edge = make_pair(p,par);
      arestas.push_back(edge);
    }

    sort(arestas.rbegin(),arestas.rend());

    vip agmax;

    for(int i = 0;i < (int)arestas.size();i++)
    {
      int u = arestas[i].nd.st;
      int v = arestas[i].nd.nd;

      if(find(u) != find(v))
      {
        agmax.push_back(arestas[i]);
        unir(u,v);
      }
    }

    monta(agmax);

    int src,dst;
    scanf("%d %d %d",&src,&dst,&peop);

    menor = INT_MAX;

    vip path;

    dfs(src-1,dst-1,path);
    sort(caminhoDFS.begin(),caminhoDFS.end());

    int medge = caminhoDFS[0].st-1;

    printf("Scenario #%d\n",++cont);

    // for(int i = 0;i < (int)caminhoDFS.size();i++)
    // {
    //   int p = caminhoDFS[i].st;
    //   int u = caminhoDFS[i].nd.st;
    //   int v = caminhoDFS[i].nd.nd;
    //   printf("%d %d %d\n",u+1,v+1,p);
    // }
    //
    // printf("\n");

    //printf("%d %d\n",n,m);
    // for(int i = 0;i < (int)arestas.size();i++)
    // {
    //   printf("%d %d %d\n",arestas[i].nd.st+1,arestas[i].nd.nd+1,arestas[i].st);
    // }
    // printf("%d %d %d\n",src,dst,peop);

    printf("Minimum Number of Trips = %d\n\n",(int)ceil(peop / (float)medge));
  }

  return 0;
}
