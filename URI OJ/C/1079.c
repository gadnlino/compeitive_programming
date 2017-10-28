#include <stdio.h>
int main (void){

int N;
int c = 0;
double A,B,C,media;

scanf("%d",&N);

for (c = 0;c < N;c++){
  scanf("%lf %lf %lf",&A,&B,&C);
  media = (A * 2 + B * 3 + C * 5) / 10;
  printf("%.1lf\n",media);
}

return 0;
}
