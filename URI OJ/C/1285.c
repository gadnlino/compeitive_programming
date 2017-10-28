#include <stdio.h>
#include <string.h>

int verifica(char numero[]);

int main(int argc, char **argv){
	int n,m,i;
	char numero[5];
	int casasValidas;
	
	while(scanf("%d %d",&n,&m) != EOF){
		casasValidas = 0;
		for(i = n;i <= m;i++){
			sprintf(numero,"%d",i);
			if(!verifica(numero)) casasValidas++;
		}
		printf("%d\n",casasValidas);
	}
	
	
	return 0;
}

int verifica(char numero[]){
	int tamanho= strlen(numero);
	int i,j;
	int iguais = 0;
	
	for(i = 0;i < tamanho -1;i++){
		for(j = i+1;j < tamanho;j++){
			if(numero[i] == numero[j]) iguais++;
		}
	}
	
	if(iguais) return 1;
	else return 0;
}

