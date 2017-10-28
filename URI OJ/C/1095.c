#include <stdio.h>
int main (void){
  int i = 1;
  int J = 60;

  for(i = 1; ;i += 3){
    J = 60 + ((-5 * (i-1)) / 3);
    printf("I=%d J=%d\n",i,J);
    if(J == 0){
      break;
    }
  }


return 0;
}
