#include <bits/stdc++.h>
#define MAXN 23
#define ulli unsigned long long int
using namespace std;

ulli f[MAXN];

ulli fat(ulli n)
{
  if(n == 0 || n == 1) return f[n] = 1;

  if(f[n]) return f[n];

  return f[n] = n * fat(n-1);
}

void init()
{
  for(int i = 0;i < MAXN;i++)
  {
    f[i] = -1;
  }
}

int main(void)
{
  int tc;
  scanf("%d",&tc);
  getchar();

  //init();

  fat(MAXN);

  for(int k = 0;k < tc;k++)
  {
    string str;
    getline(cin,str);

    map<char,int> mapa;

    for(int i = 0;i < (int)str.length();i++)
    {
      if(mapa.find(str[i]) == mapa.end()) mapa.insert(make_pair(str[i],1));
      else
      {
        mapa.find(str[i])->second = mapa.find(str[i])->second+1;
      }
    }

    printf("Data set %d: ",k+1);

    ulli tot = f[str.length()];

    // for(int i = 0;i < MAXN;i++)
    // {
    //   printf("%llu ",f[i]);
    // }
    // printf("\n");

    for(map<char,int>::iterator it = mapa.begin();it != mapa.end();it++)
    {
      //char ch = it->first;
      int i = it->second;
      //printf("%c %d\n",ch,i);

      if(i > 1) tot /= f[i];
    }

    printf("%llu\n",tot);
  }


  return 0;
}
