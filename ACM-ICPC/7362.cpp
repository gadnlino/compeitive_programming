#include <bits/stdc++.h>
#define MAXN 10005

using namespace std;

vector<int> fatores;
int memo[MAXN];

int euclides(int,int);
int fatoresp(int);
int quickTot(int);

int main(void)
{
  int t;
  scanf("%d",&t);
  memset(memo,0,MAXN * sizeof(int));

  for(int k = 0;k < t;k++)
  {
    int a,b,result = 1;
    scanf("%d %d",&a,&b);

    for(int k = 1;k <= b;k++)
    {
      if(memo[k] != 0)
      {
        result += memo[k];
        continue;
      }
      if(fatoresp(k) == 0)
      {
        fatores.push_back(k);
        int x = quickTot(k);
        result += x;
      }
      else
      {
        int x = quickTot(k);
        result += x;
      }
      fatores.clear();
    }

    printf("%d %d\n",a,result);
  }

  return 0;
}


int fatoresp(int num)
{
  int n;
  for(n = 2;n <= sqrt(num);n++)
  {
    if(!(num % n))
    {
      fatores.push_back(n);
    }
    while(!(num % n))
    {
      num /= n;
    }
  }

  if(num > 2) fatores.push_back(num);

  return fatores.size();
}


int quickTot(int n)
{
  float phi = n;

  if(n == 1)
  {
    return 1;
  }
  else
  {
    for(int k = 0;k < fatores.size();k++)
    {
      phi *= (1.0 - 1.0 / (float)fatores[k]);
    }
  }

  return memo[n] = (int)phi;
}
