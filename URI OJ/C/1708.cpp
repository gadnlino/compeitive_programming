#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  int a,b;
  cin >> a >> b;

  int lista[2] = {0,0};

  int diff,i = 0;
  do
  {
    lista[0] += a;
    lista[1] += b;
    diff = lista[1] - lista[0];
    i++;
  }while(diff < b);


  printf("%d\n",i);

  return 0;
}
