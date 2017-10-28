#include <bits/stdc++.h>

using namespace std;
bool status1;
bool status2;

void tenta(long long unsigned int,long long unsigned int,long long unsigned int,int);

int main(void)
{
  long long unsigned int num;
  scanf("%llu",&num);

  status1 = status2 = false;
  tenta(1,1,num,1);
  tenta(2,1,num,2);


  printf("%d -- %d\n",status1,status2);
  return 0;
}


void tenta(long long unsigned int num,long long unsigned int rodadas,long long unsigned int target,int init)
{
  printf("%lld -- %d -- %d -- %d\n",num,rodadas,target,init);

  if(num >= target)
  {
    if(num == target)
    {
      if(init = 1)
      {
        if(rodadas % 2 == 1 && status1 == false)
        {
          status1 = true;
          printf("true 1\n");
        }
      }
      else
      {
        if(rodadas % 2 == 0 && status2 == false)
        {
          status2 = true;
          printf("true 2\n");
        }
      }
    }

    return;
  }

  if(target - num <= 2) tenta(num + (target - num),rodadas+1,target,init);

  tenta(num + 1,rodadas + 1,target,init);
  tenta(num + 2,rodadas + 1,target,init);

}
