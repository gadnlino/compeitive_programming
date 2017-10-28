#include <bits/stdc++.h>
#define MAXN 30000
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
    tam[a] += tam[b];
    pai[b] = a;
  }
  else
  {
    tam[b] += tam[a];
    pai[a] = b;
  }
}

void init()
{
  for(int j = 0;j < MAXN;j++)
  {
    pai[j] = j;
    tam[j] = 1;
  }
}

int main(void)
{
  string tc;
  getline(cin,tc);
  stringstream ss;
  ss << tc;

  int tcases;

  ss >> tcases;

  for(int i = 0;i < tcases;i++)
  {
    int n;
    scanf("%d",&n);

    init();

    string entrada;
    int cer = 0,err = 0;
    getchar();

    while(getline(cin,entrada))
    {
      stringstream ss;
      if(entrada.empty()) break;

      ss << entrada;
      char ch;
      int u,v;

      ss >> ch >> u >> v;

      if(ch == 'q')
      {
        int paiu = find(u-1);
        int paiv = find(v-1);

        // if(paiu == paiv)
        // {
        //   printf("%d pai de %d e %d\n",paiu + 1,u,v);
        // }
        // else
        // {
        //   printf("%d pai de %d,%d pai de %d\n",paiu+1,u,paiv+1,v);
        // }

        (paiu == paiv) ? cer++ : err++;
      }
      else if(ch == 'c')
      {
        // cout << "ei\n";
        unir(u-1,v-1);
      }

    }

    i < tcases - 1 ? printf("%d,%d\n\n",cer,err) : printf("%d,%d\n",cer,err);
  }

  return 0;
}
