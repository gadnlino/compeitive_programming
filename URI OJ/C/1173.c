#include <stdio.h>

int main(int argc, char **argv){
	int vetor[10];
	int n,i;
	
	scanf("%d",&n);
	for(i = 0;i < 10;i++){
		vetor[i] = n;
		n *= 2;
	}
	for(i = 0;i < 10;i++){
		printf("N[%d] = %d\n",i,vetor[i]);
	}
	
	return 0;
}

