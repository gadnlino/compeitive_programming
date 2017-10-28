#include <bits/stdc++.h>
#define MAXN 100100
using namespace std;

int sol,bai;
int solds[MAXN];

int achaDir(int pos)
{
  int cara = -1;
  // printf("pos = %d sol %d\n",pos,sol);

  for(int i = pos+1;i < sol;i++)
  {
    // printf("%d ",solds[i]);
    cara = solds[i];
    if(cara > 0) break;
  }

  return cara;
}

int achaEsq(int pos)
{
  int cara = -1;
  // printf("pos = %d\n",pos);

  for(int i = pos-1;i > -1;i--)
  {
    // printf("%d ",solds[i]);
    cara = solds[i];
    if(cara > 0) break;
  }

  return cara;
}

int main(void)
{

  while(true)
  {
    scanf("%d %d",&sol,&bai);
    if(sol == 0 && bai == 0) break;


    for(int i = 0;i < sol;i++)
    {
      solds[i] = -1;
    }

    for(int i = 0;i < sol;i++)
    {
      solds[i] = i;
    }

    for(int i = 0;i < bai;i++)
    {
      int ini,end;
      scanf("%d %d",&ini,&end);
      // printf("%d --> %d\n",ini,end);
      for(int j = ini - 1;j < end;j++)
      {
        // printf("%d ",solds[j]+1);
        solds[j] = -1;
      }
      // printf("\n");

      int esq = achaEsq(end-1);
      int dir = achaDir(end-1);

      esq != -1 ? printf("%d ",esq+1) : printf("* ");
      dir != -1 ? printf("%d\n",dir+1) : printf("*\n");

    }

    printf("-\n");
  }


  return 0;
}
