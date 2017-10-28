#include <stdio.h>

int main(){
	double numerador = 1;
	double denominador = 1;
	double soma = 0;

	while(numerador <= 39){
		soma += numerador/denominador;
		numerador += 2;
		denominador *= 2;
	}

	printf("%.2f\n",soma);
	
	return 0;
}
