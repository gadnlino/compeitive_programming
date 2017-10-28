#include <stdio.h>

int main(int argc, char **argv){
	int n,i,j = 0;
	int vetor[1000];
	
	scanf("%d",&n);
	
	for(i = 0; i < 1000; i++){
		vetor[i] = j;
		j++;
		if(j == n) j = 0;
	}
	
	for(i = 0;i < 1000;i++){
		printf("N[%d] = %d\n",i,vetor[i]);
	}
	
	return 0;
}

