#include <bits/stdc++.h>
#define MAXN 10007
using namespace std;

int arr[MAXN];

int bubbleSort(int*,int);

int main(void)
{
  int tc;
  scanf("%d",&tc);

  for(int i = 0;i < tc;i++)
  {
    int tam;
    scanf("%d",&tam);

    memset(arr,0,tam * sizeof(int));

    for(int j = 0;j < tam;j++)
    {
      scanf("%d",&arr[j]);
    }

    int x = bubbleSort(arr,tam);

    printf("Optimal train swapping takes %d swaps.\n",x);
  }


  return 0;
}


int bubbleSort(int* arr,int tam)
{
  int cont = 0;

  for(int i = 0;i < tam;i++)
  {
    for(int j = 0;j < tam - 1 - i;j++)
    {
      if(arr[j] > arr[j+1])
      {
        int temp = arr[j+1];
        arr[j+1] = arr[j];
        arr[j] = temp;
        cont++;
      }
    }
  }

  return cont;
}
