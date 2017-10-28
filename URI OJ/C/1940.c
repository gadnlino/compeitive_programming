#include <stdio.h>
#define TAM 1000

int pontJog[TAM];
int scanner[TAM];

int main(void){
  int jog,rod;
  scanf("%d %d",&jog,&rod);
  int maior = 0,i;

  for(i = 0;i < jog * rod;i++){
    scanf("%d",&pontJog[i]);
  }

  for(i = 0;i < jog * rod;i++){
    scanner[i % jog] = 0;
  }
  for(i = 0;i < jog;i++){
    printf("%d\t",scanner[i]);
  }
  for(i = 0;i < jog * rod;i++){
    scanner[i % jog] += pontJog[i];
  }
  printf("\n");

  for(i = 0;i < jog;i++){
    printf("%d\t",scanner[i] );
    if(scanner[i] >= maior){maior = i;}
  }

  printf("\n");
  printf("%d\n",maior);

  return 0;
}
