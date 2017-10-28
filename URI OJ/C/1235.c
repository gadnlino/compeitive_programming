#include <stdio.h>
#include <string.h>
#define TAM 105

int main(){
    int n,i,j;
    scanf("%d",&n);
    getchar();
    char str[TAM];

    for(i = 0;i < n;i++){
      gets(str);

      for(j = (strlen(str) / 2) - 1;j > -1;j--){
        printf("%c",str[j]);
      }

      for(j = strlen(str) - 1;j >= strlen(str) - (strlen(str) / 2);j--){
        printf("%c",str[j]);
      }

      printf("\n");

    }

    return 0;
}
