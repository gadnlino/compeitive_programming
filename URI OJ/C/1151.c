#include <stdio.h>
int main (void){

int N,a,b,c;
int d = 0;
 a = 0;
 b = 1;

  scanf("%d",&N);
  printf("%d %d",a,b);
  c = a + b;
  for (d = 0;d < N - 2;d++){
    printf(" %d",c);
    a = b;
    b = c;
    c = a + b;
  }
  printf("\n");

  return 0;
}
