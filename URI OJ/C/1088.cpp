#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

int arr[MAXN],cont;
void quicksort(int*,int,int);
int part(int*,int,int);

int main(void)
{
  int tam;
  while(1)
  {
    scanf("%d",&tam);
    if(tam == 0) break;

    memset(arr,0,tam * sizeof(int));

    cont = 0;

    for(int i = 0;i < tam;i++)
    {
      scanf("%d",&arr[i]);
    }

    quicksort(arr,0,tam-1);
    /*
    for(int l = 0;l < tam;l++)
    {
      printf("%d ",arr[l]);
    }

    printf("\n");
    */
    cont % 2 == 1 ? printf("Marcelo\n") : printf("Carlos\n");
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

  for(j = start,i = start -1;j < end;j++)
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
