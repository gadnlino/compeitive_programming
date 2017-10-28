#include <stdio.h>
int main(void){
  int N,i;
  float C;
  int dias = 0;

  scanf("%d",&N);
  for(i = 0;i < N;i++){
    scanf("%f",&C);
    do{
      C = C / 2;
      dias++;
    }while(C > 1);

    printf("%d dias\n",dias);
    dias = 0;
  }

return 0;
}
