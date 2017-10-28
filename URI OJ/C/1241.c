#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
	char x[1001],y[1001];
	int n,i,k,tamanho1,tamanho2;
	int invalido;
	
	scanf("%d",&n);
	
	for(i = 0;i < n;i++){
		scanf("%s %s",x,y);
		tamanho1 = strlen(x);
		tamanho2 = strlen(y);
		invalido = 0;
		
		for(k = tamanho2;k >= 0;k--){
			if(x[tamanho1] != y[k]){
				invalido = 1;
				break;
			}
			tamanho1--;
		}
		
		if(invalido == 1){
			printf("nao encaixa\n");
		}
		else printf("encaixa\n");
	}
	
	
	return 0;
}
