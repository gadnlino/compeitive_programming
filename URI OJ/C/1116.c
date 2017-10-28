#include <stdio.h>
int main (void){
  int N,X,Y;
  int c = 0;
  double D;

  scanf("%d",&N);

  for (c = 0;c < N;c++){
    scanf("%d %d",&X,&Y);
    if(Y == 0){
      printf("divisao impossivel\n");
    }
    else{
      D = (double)(X) / Y;
      printf("%.1lf\n",D);
    }
  }
return 0;
}
