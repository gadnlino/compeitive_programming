#include <stdio.h>

int main(void){
  long long int qtd,i;

  scanf("%lld",&qtd);

  for(i = 0;i < qtd - 1;i++){
    printf("Ho ");
  }

  if(qtd > 0) printf("Ho!\n");

  return 0;
}
