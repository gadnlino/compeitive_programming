#include <stdio.h>
int main(void){
  int i = 1;

  for(i = i;i <= 9;i += 2){
    printf("I=%d J=7\n",i);
    printf("I=%d J=6\n",i);
    printf("I=%d J=5\n",i);
  }

return 0;
}
