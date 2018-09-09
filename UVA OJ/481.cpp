#include <cstdio>
#include <iostream>
#include <algorithm>

#define MAXN 100004
using namespace std;
int pre[MAXN];
int tam[MAXN];
int tail[MAXN];
int arr[MAXN];
int maxidx;

void printa_lis(int idx){
  if(idx < 0) return;

  int ele = arr[idx];
  idx = pre[idx];
  printa_lis(idx);
  printf("%d\n",ele);
}

int busca(int beg,int end,int ele){
  int mid = beg + (end-beg)/2;
  if(end-beg <= 1) return max(end,beg);
  if(arr[tail[mid]] < ele) return busca(mid,end,ele);
  else if(arr[tail[mid]] >= ele) return busca(beg,mid,ele);
}

int main(){
  int n = 0;

  while(scanf("%d",&arr[n++]) == 1)

  for(int i = 0;i < n;i++) tam[i] = 1; //tamanho da maior subsequencia terminando em i
  pre[0] = -1;
  tail[0] = 0;

  maxidx = -1;//o indice de onde termina a sequencia maxima
  int len = 1;//grava o tamanho da maior subsequencia

  for(int i = 1;i < n;i++){
    if(arr[i] > arr[tail[len-1]]){ //aumentar o tamanho da sequencia
      pre[i] = tail[len-1];
      tail[len] = i;
      // tam[len] = tam[tail[len-1]] + 1;
      len++;
    }
    else if(arr[i] < arr[tail[0]]){ // é menor do que o menor da sequencia
      tail[0] = i;
    }
    else{
      int pos = busca(-1,len-1,arr[i]);
      // tam[i] = tam[tail[pos]];
      tail[pos] = i;
      pre[i] = tail[pos-1];
    }
  }

  // for(int i = 0;i < n;i++) printf("%d ",arr[i]);
  // printf("\n");
  // for(int i = 0;i < n;i++) printf("%d ",pre[i]);
  // printf("\n");
  // for(int i = 0;i < len;i++) printf("%d ",tail[i]);
  // printf("\n");

  printf("%d\n-\n",len);
  int idx = tail[len-1];
  printa_lis(idx);

  return 0;
}
