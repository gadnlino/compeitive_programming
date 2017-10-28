#include <bits/stdc++.h>

using namespace std;

//divisor,não divisor,multiplo,não multiplo
vector<int> mult;

int main(void)
{
  int a,b,c,d,j;

  scanf("%d %d %d %d",&a,&b,&c,&d);

  for(int k = 2;k <= (int)sqrt(c);k++)
  {
    if(c % k == 0)
    {
      mult.push_back(k);
      mult.push_back(c / k);
    }
  }

  sort(mult.begin(),mult.end());

  for(j = 0;j < mult.size();j++)
  {
    if(mult[j] % a == 0 && mult[j] % b != 0 && d % mult[j] != 0)
    {
      printf("%d\n",mult[j]);
      break;
    }
  }

  if(j == mult.size())
  {
    printf("-1\n");
  }

  return 0;
}
