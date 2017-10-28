#include <stdio.h>
#include <stdlib.h>
int main(void){

  int A,B,C,D,E;

  scanf("%d %d %d",&A,&B,&C);
  D = (A + B + abs(A - B)) / 2;
  E = (C + D + abs(C - D)) / 2;

  printf("%d eh o maior\n",E);

return 0;
}
