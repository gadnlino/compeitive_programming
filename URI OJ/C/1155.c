#include <stdio.h>
int main(void){
	
	double soma = 0, c = 1, i = 1;
	
	for(i = i;i <= 100;i++){
		c = 1 / i;
		soma += c;
	}
	
	printf("%.2lf\n",soma);
	
	return 0;
}
