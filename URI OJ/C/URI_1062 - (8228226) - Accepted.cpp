#include <bits/stdc++.h>

using namespace std;

bool verifica(int,stack<int>);

int main(void)
{
  int v;
  while(true)
  {
    scanf("%d",&v);
    //printf("v = %d\n",v);

    if(v == 0) break;

    while(true)
    {
      stack<int> init,inter,fim;
      bool sair = false;

      for(int i = 0;i < v;i++)
      {
        int vg;
        scanf("%d",&vg);

        if(vg == 0)
        {
          sair = true;
          break;
        }

        init.push(vg);
      }

      if(sair) break;


      while(!init.empty())
      {
        int u = init.top();
        init.pop();

        if(inter.empty())
        {
          inter.push(u);
          // printf("colocando %d em inter\n",u);
        }
        else
        {
          if(u > inter.top())
          {
            inter.push(u);
            // printf("colocando %d em inter\n",u);
          }
          else
          {
            while(!inter.empty())
            {
              if(u < inter.top())
              {
                //printf("colocando %d em fim\n",inter.top());
                fim.push(inter.top());
                inter.pop();
              }
              else break;
            }

            inter.push(u);
          }
        }
      }

      while(!inter.empty())
      {
        int d = inter.top();
        inter.pop();
        fim.push(d);
        // printf("colocando %d em fim\n",d);
      }
      /*
      while(!fim.empty())
      {
        int u = fim.top();
        fim.pop();

        printf("%d ",u);
      }
      printf("\n");
      */
      verifica(v,fim) ? printf("Yes\n") : printf("No\n");
    }
    printf("\n");
  }

  return 0;
}


bool verifica(int v,stack<int> fim)
{
  int val = 1;

  while(!fim.empty())
  {
    int v = fim.top();
    fim.pop();

    //printf("%d -- %d\n",val,v);
    if(val != v) return false;
    val++;
  }

  return true;
}
