#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
  int cas,cont = 0;
  while(1)
  {
    scanf("%d",&cas);
    if(cas == 0) break;

    map<int,int> mapa;
    double media = 0;
    int peo = 0;

    for(int i = 0;i < cas;i++)
    {
      int a,b;
      scanf("%d %d",&a,&b);
      peo += a;
      media += b;

      if(mapa.find(b/a) != mapa.end())
      {
        mapa[b/a] = mapa[b/a] + a;
      }
      else
      {
        mapa[b/a] = a;
      }
    }

    printf("Cidade# %d:\n",++cont);

    map<int,int>:: iterator it = mapa.begin();
    for(;it != mapa.end();++it)
    {
      pair<int,int> p = *it;
      int f = p.first,g = p.second;
      //media += f;
      it == mapa.begin() ? printf("%d-%d",g,f) : printf(" %d-%d",g,f);
    }

    printf("\n");


    media = media / peo;
    //printf("peo = %d\n",peo);
    //printf("media = %lf\n",media);

    printf("Consumo medio: %.2lf m3.\n",media - 0.004714);
    printf("\n");
  }


  return 0;
}
