#include <stdio.h>
#include <string.h>
#define TAM 51

int main(void){
    char str[TAM];
    int n ,i ,j ,chave;
    int len;

    scanf("%d",&n);
    for(i = 0; i < n;i++){
        gets(str);
        scanf("%d",&chave);
        len = strlen(str);
        for(i = 0 ; i < len; i++){
            if(str[i] >= 'A' && str[i] <= 'Z'){
                if(str[i] + chave > 'Z'){
                    str[i] += chave - 'Z';
                }
                else{
                    str[i] += chave;
                }
            }
        }
         printf("%s",str);
    }

    return 0;
}

/*char cifra(char str[]){
    int i,len;
    char str2[TAM];
    int chave;

    gets(str2);
    len = strlen(str);
    scanf("%d",chave);

    for(i = 0;i < len;i++){
        if(str2[i] >= 'A' && str2[i] <= 'Z'){
            if(str2[i] + chave > 25){
                str2[i] += chave - 26;
            }
            else{
                str2[i] += chave;
            }
        }
    }

    return str2;
}*/
