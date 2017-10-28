#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  int tc;
  scanf("%d",&tc);

  for(int j = 0;j < tc;j++)
  {
    string s1,s2;
    cin >> s1 >> s2;

    bool achou = false;

    // printf("de frente pra tras\n");
    for(int i = 0;i < 2*s2.length();i++)
    {
      achou = true;

      for(int u = 0;u < s1.length();u++)
      {
        // printf("%c-%d -- %c-%d\n",s1[u],u,s2[(u + i) % s2.length()],(u + i) % s2.length());

        if(s1[u] != s2[(u + i) % s2.length()])
        {
          achou = false;
          break;
        }
      }
      // printf("\n");

      if(achou == true) break;
    }

    if(achou == false)
    {
      // printf("de tras pra frente\n");

      for(int i = 0;i < 2*s2.length();i++)
      {
        achou = true;

        for(int u = 0;u < s1.length();u++)
        {
          // printf("%c-%d -- %c-%d\n",s1[u],u,s2[(s2.length() -1) - ((u+i) % (s2.length()))],s2.length() -1 -((u+i) % (s2.length())));

          if(s1[u] != s2[(s2.length() -1) - ((u+i) % (s2.length()))])
          {
            // printf("aqui\n");
            achou = false;
            break;
          }
        }

        // printf("%d\n",achou);

        if(achou == true) break;
      }

    }

    achou ? printf("S\n") : printf("N\n");
  }

  return 0;
}
