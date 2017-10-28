#include <stdio.h>

int fib(int num);

int calls = 0;

int main(void){
  int numero;
  int ct;
  int i;

  scanf("%d",&ct);

  for(i = 0;i < ct;i++){
    scanf("%d",&numero);
    printf("fib(%d) = %d calls = %d\n",numero,calls,fib(numero));
    calls = 0;
  }
  return 0;
}

int fib(int num){
  if(num == 0) return 0;
  if(num == 1) return 1;

  calls += 2;

  return fib(num - 1) + fib(num - 2);
}
