#include <stdio.h>

int main(int argc, char **argv){
	int n;
	int alcool = 0,gasolina= 0,diesel = 0;
	
	
	while(1){
		scanf("%d",&n);
		switch (n) {
			case 1:
				alcool++;
				break;
			case 2:
				gasolina++;
				break;
			case 3:
				diesel++;
				break;
			case 4:
				printf("MUITO OBRIGADO\nAlcool: %d\nGasolina: %d\nDiesel: %d\n",alcool,gasolina,diesel);
				return 0;
		}
	}
}

