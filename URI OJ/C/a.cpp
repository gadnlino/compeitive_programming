#include <bits/stdc++.h>
#define MAXN 1003
using namespace std;

int main(void)
{
  int a,b;
  scanf("%d %d",&a,&b);

  int arr[MAXN],range[MAXN];
  for(int i = 0;i < b;i++)
  {
    int k;
    scanf("%d",&k);
    arr[i] = k;
  }

  int t = a/b;
  memset(range,0,b * sizeof(int));

  for(int i = 0;i < a;i++)
  {
    bool is = true;
    for(int j = 0;j < b;j++)
    {
      range[j] = (i + j*t) % a;
      printf("%d ",range[j]);
    }
    printf("\n");

    for(int l = 0;l < b;l++)
    {
      if(arr[l] > range[l] && arr[l] <= range[l+1]) continue;
      else
        is = false;
        break;
    }
  }



  return 0;
}
