#include <stdio.h>
int main(void){
  int X;
  int C = 0;

  scanf("%d",&X);

  if (X % 2 == 0){
    X = X + 1;
    for(X = X ; C < 6 ; C++){
      printf("%d\n",X);
      X += 2;
    }
  }
  else{
    for (X = X ; C < 6 ; C++){
      printf("%d\n",X);
      X += 2;
    }
  }

return 0;
}
