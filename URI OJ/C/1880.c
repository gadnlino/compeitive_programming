#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindromo(int numerobase10,int baseatual);

int main(int argc, char **argv){
	int numerobase10,n,i,j,passo;
	int baseatual = 2;
	int *baseverdade = (int*)calloc(15,sizeof(int));
	
	scanf("%d",&n);
	
	for(i = 0;i < n;i++){
		passo = 0;
		scanf("%d",&numerobase10);
		for(;baseatual <= 16;baseatual++){
			if(palindromo(numerobase10,baseatual)){ 
				*(baseverdade + passo) = baseatual;
				passo++;
			}
		}
		if (passo > 0){
			for(j = 0;j < passo;j++){
				printf("%d ",*(baseverdade + j));
			}
			printf("\n");
		}
		else printf("-1\n");
	}
	
	return 0;
}

int palindromo(int numerobase10,int baseatual){
	int *auxiliar = (int*)malloc(32 * sizeof(char));
	int quociente = numerobase10,resto,indice = 0,indicereverso = 0;
	int palindromo = 1;
	
	while(quociente != 0){
		resto = quociente % baseatual;
		quociente /= baseatual;
		*(auxiliar + indice) = resto;
		indice++;
	}
	
	for(;indice >= 0;indice--){
		if(*(auxiliar + indice) == *(auxiliar + indicereverso)){ 
			palindromo = 1;
			printf("oi\n");
		}
		else palindromo = 0;
		
		if (!palindromo) return palindromo;
		indicereverso++;
	}
	return palindromo;	
}
