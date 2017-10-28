#include <stdio.h>
#include <string.h>

int main (){
	char frase1[101],frase2[101];
	int n,contador1,contador2,tamanho;
	char temp;
	int reverso = 0;

	scanf("%d",&n);

	for(contador1 = 0;contador1 < n;contador1++){
		gets(frase1);
		strcpy(frase2,frase1);
		tamanho = strlen(frase1);
		for(contador2 = tamanho/2 - 1;contador2 >-1;contador2--){
			frase1[reverso] = frase2[contador2];
			reverso++;
		}

		reverso++;

		for(contador2 = tamanho;contador2 > tamanho/2;contador2--){
			frase1[reverso] = frase2[contador2];
			reverso++;
		}
		fputs(frase1,stdout);
		printf("\n");
	}
	return 0;
}