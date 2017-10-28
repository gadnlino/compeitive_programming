#include <bits/stdc++.h>
#define MAXN 100004
using namespace std;

int pos[MAXN];

int confere(int,int,int);

int main(void)
{
  int circ,az;
  scanf("%d %d",&circ,&az);

  memset(pos,0,circ * sizeof(int));

  for(int i = 0;i < az;i++)
  {
    int a;
    scanf("%d",&a);
    pos[a] = 1;
  }

  int tamped = circ / az;

  int cont;
  bool da = false;

  for(int i = 0;i < tamped;i++)
  {
    cont = 0;
    for(int j = 0;j < az;j++)
    {
      int low = i + j * tamped;
      int high = i + (j+1) * tamped;
      //printf("%d-- %d\n",low,high);

      int x = confere(low,high,circ);
      if(x != 1) break;
      cont += x;
    }
    if(cont == az)
    {
      da = true;
      break;
    }
  }

  da ? printf("S\n") : printf("N\n");

  return 0;
}

int confere(int a,int b,int tam)
{
  int cont = 0;

  for(int i = a;i < b;i++)
  {
    //printf("%d ",pos[i % tam]);
    if(pos[i % tam]) cont++;
  }

  //printf("\n");

  return cont;
}
