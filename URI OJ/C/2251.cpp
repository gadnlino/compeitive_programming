#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  int d;
  int cont = 0;

  while(scanf("%d",&d))
  {
    if(d == 0) break;
    printf("Teste %d\n",++cont);

    printf("%d\n\n",(int)(pow(2,d)-1));
  }

  return 0;
}
