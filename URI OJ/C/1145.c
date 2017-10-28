#include <stdio.h>
int main(void){
  int X,Y;
  int i = 1;
  int c = 0;

  scanf("%d %d",&X,&Y);
  for (i = i;i <= Y;i++){
    c++;
    if(c == X){
      printf("%d\n",i);
      c = 0;
    }
    else{
      printf("%d ",i);
    }
  }

return 0;
}
