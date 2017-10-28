#include <bits/stdc++.h>
#define MAXN 1004
using namespace std;

vector<int> la[MAXN];
int grau[MAXN];

int main(void)
{
  int n,min;
  while(scanf("%d",&n) != EOF)
  {
    memset(grau,0,n * sizeof(int));
    min = 0;

    for(int i = 0;i < n;i++)
    {
      int q,b;
      cin >> q;
      if(q != 0)
      {
        for(int y = 0;y < q;y++)
        {
          cin >> b;
          la[b-1].push_back(i);
          grau[i]++;
        }
      }
    }
    vector<int> ord;
    /*
    for(int i = 0;i < n;i++)
    {
      printf(" %d ->%d\n",i,grau[i]);
    }
    */
    
   
    for(int i = 0;i < n;i++)
    {
      if(!grau[i]) ord.push_back(i);
    }
    
    if(ord.empty())
    {
      printf("-1\n");
      continue;
    }
    else
    {
      for(int i = 0;i < (int)ord.size();i++)
      {
        int src = ord[i];
        min++;
        for(int j = 0;j < (int)la[src].size();j++)
        {
          int dst = la[src][j];
          grau[dst]--;
          if(!grau[dst]) ord.push_back(dst);
        }
      }
    }
       printf("tam = %d\n",(int)ord.size());
    (int)ord.size() == n? printf("%d\n",min) : printf("-1\n");

    for(int i = 0;i < n;i++)
    {
      la[i].clear();
    }
  }

  printf("\n");

  return 0;
}
