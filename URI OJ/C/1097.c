#include <stdio.h>
int main(void){
  int i = 1;
  int j = 7;

  for(i = i;i <= 9;i += 2){
    printf("I=%d J=%d\n",i,j);
    printf("I=%d J=%d\n",i,j-1);
    printf("I=%d J=%d\n",i,j-2);
    j += 2;
  }

return 0;
}
