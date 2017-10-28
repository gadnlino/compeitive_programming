#include <stdio.h>
int main(void){
    int a, b;
    int duracao;

    scanf("%d %d",&a,&b);

    if(b <= a){
			duracao =  (b  -  a) + 24;
	}
	else duracao = b - a;
	
	printf("O JOGO DUROU %d HORA(S)\n",duracao);
	
	return 0;
}
