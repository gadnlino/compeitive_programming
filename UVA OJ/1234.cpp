#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#define ii pair<int,int>
#define vip pair<int,ii>
#define st first
#define nd second
#define MAXN 100000

using namespace std;

int pai[MAXN];
int tam[MAXN];

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

void init()
{
   for(int i = 0;i < MAXN;i++)
   {
      pai[i] = i;
      tam[i] = 1;
   }
}

int main()
{
   int tc;
   while(true)
   {

      scanf("%d",&tc);
      if(tc == 0) break;

      for(int i = 0;i < tc;i++)
      {
         vector<vip> arestas;
         
         int n,m;
         scanf("%d %d",&n,&m);

         init();

         for(int j = 0;j < m;j++)
         {
            int u,v,c;
            scanf("%d %d %d",&u,&v,&c);
            arestas.push_back(make_pair(-c,make_pair(u-1,v-1)));
         }

         sort(arestas.begin(),arestas.end());
         int soma = 0;

         for(int j = 0;j <(int)arestas.size();j++ )
         {
            int u = arestas[j].nd.st;
            int v = arestas[j].nd.nd;
            int cst = arestas[j].st;

            if(find(u) != find(v))
            {
               unir(u,v);
            }
            else
            {
               // printf("ciclo\n");
               soma += -cst;
            }
         }

         printf("%d\n",soma);
      }
   }

   return 0;
}
