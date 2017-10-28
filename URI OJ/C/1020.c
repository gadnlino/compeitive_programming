#include <stdio.h>
int main(void){
  int N,d,m,a;

  scanf("%d",&N);

  a = N / 365;
  d = N % 365;
  m = d / 30;
  d = d % 30;

  printf("%d ano(s)\n",a);
  printf("%d mes(es)\n",m);
  printf("%d dia(s)\n",d);

return 0;
}
