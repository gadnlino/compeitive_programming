#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void){
	char sentence[51];
	int i,cont;
	int tamanho;


    while(gets(sentence) != NULL){
        cont = 0;
        tamanho = strlen(sentence);

        for(i = 0;i < tamanho ;i++){
            if((sentence[i] >= 'A' && sentence[i] <= 'Z') || (sentence[i] >= 'a' && sentence[i] <= 'z')){
                cont++;
                if(cont % 2 == 1){
                    if(sentence[i] >= 'a' && sentence[i] <= 'z'){
                      printf("%c",toupper(sentence[i]));
                    }
                    else printf("%c",sentence[i]);
                }
                if(cont % 2 == 0){
                    if(sentence[i] >= 'A' && sentence[i] <= 'Z'){
                        printf("%c",tolower(sentence[i]));
                    }
                    else printf("%c",sentence[i]);
                }

            }
            else printf(" ");
        }

        printf("\n");
    }

	return 0;
}
