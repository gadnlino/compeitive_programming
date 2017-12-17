#include <bits/stdc++.h>
#define MAXN 1003
using namespace std;

int arr[MAXN];
int mrc[MAXN];
int used[MAXN];
vector<vector<int> > somas;
set<vector<int> > jah;

void acha(int qual,int i,int n)
{
  if(i == n)
  {
    vector<int> v;
    int soma = 0;

    for(int u = 0;u < n;u++)
    {
      if(mrc[u])
      {
        v.push_back(arr[u]);
        soma += arr[u];
      }
    }

    if(soma == qual && jah.find(v) == jah.end())
    {
      //jah.find(v) == jah.end() ? printf("nova soma\n") : printf("ja tem a soma\n");
      somas.push_back(v);
      jah.insert(v);
    }

    return;
  }

  mrc[i] = 0;
  acha(qual,i+1,n);

  mrc[i] = 1;
  acha(qual,i+1,n);
}

int main(void)
{
  int qual,n;

  while(true)
  {
    scanf("%d %d",&qual,&n);
    if(qual == n && n == 0) break;

    for(int i = 0;i < n;i++)
    {
      scanf("%d",&arr[i]);
    }

    acha(qual,0,n);

    printf("Sums of %d:\n",qual);

    sort(somas.rbegin(),somas.rend());

    if(somas.empty()) printf("NONE\n");
    else
    {
      for(int i = 0;i < (int)somas.size();i++)
      {
        for(int j = 0;j < (int)somas[i].size();j++)
        {
          j < (int)somas[i].size()-1 ?  printf("%d+",somas[i][j]) : printf("%d\n",somas[i][j]);
        }
      }
    }

    somas.clear();
    jah.clear();
  }

  return 0;
}
