//not finished yet

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> verifica(int,int,long long unsigned int);

int main()
{
  int tc;
  scanf("%d",&tc);

  for(int i = 0;i < tc;i++)
  {
    //cont = quantas vezes eu achei a diff
    int oc,diff,cont = 0;
    long long unsigned int mod;

    scanf("%d %d %llu",&oc,&diff,&mod);
    printf("%d %d %llu\n",oc,diff,mod);

    vector<int> resposta = verifica(oc,diff,mod);

    for(int j = 0;j < (int)resposta.size();j++)
    {
      j < (int)resposta.size() - 1 ? printf("%d ",resposta[j]) :
        printf("%d\n",resposta[j]);
    }
  }


  return 0;
}


vector<int> verifica(int oc,int diff,long long unsigned int mod)
{
  vector<int> toReturn;
  int cont = 0;
  int fat = 1;

  while(cont < oc)
  {
    int a = 3 * fat;
    int b = 4 * fat;
    int c = 5 * fat++;
    printf("%d %d %d\n",a,b,c);
    if(b - a == diff) cont++;
  }

  return toReturn;
}
