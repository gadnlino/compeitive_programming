#include <stdio.h>
#include <string.h>
#define MAX 129

char str[MAX];
int main(void){
  int ct,i,j,in,out;

  scanf("%d",&ct);
  getchar();

  for(i = 0;i < ct;i++){
    in = out = 0;

    gets(str);

    for(j = 0;j < strlen(str);j++){
      if(str[j] == '[' || str[j] == '('){
        in++;
      }
      if(str[j] == ']' || str[j] == ')'){
        out++;
      }
    }

    if(in == out){  printf("Yes\n");}
    else if(str[0] == '\0'){  printf("Yes\n");}
    else{ printf("No\n");}
  }

  return 0;

}
