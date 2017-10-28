#include <bits/stdc++.h>

using namespace std;

int main()
{
   int tc;
   scanf("%d",&tc);

   for(int i = 0;i < tc;i++)
   {
      vector<int> pessoas;
      int n,m;
      scanf("%d %d",&n,&m);


      for(int j = 0;j < n;j++)
      {
         pessoas.push_back(j+1);
      }

      int cont = (m-1) % pessoas.size();

      while(pessoas.size() > 1)
      {
         pessoas.erase(pessoas.begin() + cont);
         cont = (cont + m-1) % pessoas.size();
      }

      printf("Case %d: %d\n",i+1,pessoas[0]);
   }

      return 0;
}
