#include <stdio.h>
#include <ctype.h>
int main(void){
    char expressao[8],operacao;
    int n1,d1,n2,d2;
    int search;
    int i,casosDeTeste;

    scanf("%d"&casosDeTeste);

    for(i = 0;i < casosDeTeste;i++){
        gets(expressao);

        for(search = 0;expressao[search] = '\0';search++){
            if(expressao[search] == '+' || expressao[search] == '-' ||
               expressao[search] == '*' || expressao[search] == '/'){
                    scanf("%c",&operacao);
               }
        }
        search = 0;
        for(expressao[search];expressao[search] == '\0';search++){
            if(expressao[search] >= '0' && expressao[search] <= '9'){

            }
        }


	return 0;
}
