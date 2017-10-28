#include <bits/stdc++.h>
#define MAXN 10003
using namespace std;

int arr[MAXN],cont;

void quicksort(int*,int,int);
int part(int*,int,int);

int main(void)
{
  int tc;
  scanf("%d\n",&tc);

  for(int i = 0;i < tc;i++)
  {
    int tam;
    scanf("%d",&tam);
    memset(arr,0,tam * sizeof(int));

    cont = 0;

    for(int j = 0;j < tam;j++)
    {
      scanf("%d",&arr[j]);
    }

    quicksort(arr,0,tam - 1);

    printf("%d\n",cont);
  }

  return 0;
}


void quicksort(int* arr,int start,int end)
{
  if(start < end)
  {
    int pIndex = part(arr,start,end);
    quicksort(arr,start,pIndex-1);
    quicksort(arr,pIndex+1,end);
  }
}


int part(int* arr,int start,int end)
{
  int pivot = arr[end],i,j;

  for(j = start,i = start-1;j < end;j++)
  {
    if(arr[j] < pivot)
    {
      i++;
      if(arr[i] != arr[j])
      {
        swap(arr[i],arr[j]);
        cont++;
      }
    }
  }

  if(arr[i+1] != arr[end])
  {
    swap(arr[i+1],arr[end]);
    cont++;
  }

  return i+1;
}
