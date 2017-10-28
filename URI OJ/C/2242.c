#include <stdio.h>
#include <string.h>
#define TAM 51

int isVowel(char);

char str[TAM];
char scr1[TAM];
char scr2[TAM];

int main(void){
  int i,c1 = 0,c2 = 0;
  gets(str);

  for(i = 0;i < strlen(str);i++){
    if(isVowel(str[i])){
      scr1[c1++] = str[i];
    }
  }

  scr1[c1] = '\0';

  for(i = strlen(str);i > -1;i--){
    if(isVowel(str[i])){
      scr2[c2++] = str[i];
    }
  }

  scr2[c2] = '\0';

  if(strcmp(scr1,scr2) == 0){
    printf("S\n");
  }
  else{printf("N\n");}

  return 0;
}


int isVowel(char a){
  if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'){return 1;}
  return 0;
}
