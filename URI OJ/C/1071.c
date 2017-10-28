#include <stdio.h>
int main(void){
  int X,Y,i;
  int total = 0;

  scanf("%d %d",&X,&Y);

  if(X > Y && Y % 2 == 0){
    for(i = Y + 1;i < X;i += 2){
      total += i;
    }
  }
  else if(X > Y && Y % 2 !=  0){
    for(i = Y + 2;i < X;i += 2){
      total += i;
    }
  }
  else if(X < Y && X % 2 == 0){
    for(i = X + 1;i < Y;i += 2){
      total += i;
    }
  }
  else if(X < Y && X % 2 != 0){
    for(i = X + 2;i < Y;i += 2){
      total += i;
    }
  }
  printf("%d\n",total);

return 0;
}
