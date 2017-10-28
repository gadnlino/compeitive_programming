#include <bits/stdc++.h>
#define MAXN 100000

using namespace std;

vector<int> la[MAXN];
vector<int> ordt;
int grau[MAXN];

int main(void)
{
  int t;
  scanf("%d",&t);

  for(int i = 0;i < t;i++)
  {
    int doc,dep;
    bool temLoop = false;
      scanf("%d %d",&doc,&dep);
    
      memset(grau,0,doc * sizeof(int));

    for(int j = 0;j < dep;j++)
      {
        int a,b;
        scanf("%d %d",&a,&b);
        la[a - 1].push_back(b - 1);
        grau[b - 1]++;
      }

      for(int k = 0;k < doc;k++)
      {
        if(grau[k] == 0)
        {
          ordt.push_back(k);
        }
      }

      if(ordt.empty())
      {
        temLoop = true;
      } 
      else
      {
        for(int a = 0;a < ordt.size();a++)
          {
              int v = ordt[a];
              for(int i = 0;i < la[v].size();i++)
              {
                  int o = la[v][i];
                  grau[o]--;
                  if(grau[o] == 0)
                  {
                      ordt.push_back(o);
                  }
              }
          }

          for(int p = 0;p < doc;p++)
          {
            if(grau[p] > 0)
          {
            temLoop = true;
          }
          }
      }

      

      if(temLoop == false) printf("NAO\n");
      else printf("SIM\n");

      ordt.clear();

      for(int j = 0;j < doc;j++)
      {
        la[j].clear();
      }
  }
  
  return 0;
}