#include <stdio.h>
#include <math.h>

int main(){
	int Ui = 0,Ri = 0,Ii = 0;
	int n,numeros[3],i;
	float res;

	
	while(1){
		scanf("%d",&n);
		if(n == 0) break;	
		for(i = 0;i < n;i++){
		
			scanf("%d %d %d",&numeros[0],&numeros[1],&numeros[2]);
			
			res = fmodf(log2(numeros[0]),1);
			if(res == 0){Ui++;}
			res = fmodf(log2(numeros[1]),1);
			if(res == 0){Ri++;}
			res = fmodf(log2(numeros[2]),1);
			if(res == 0){Ii++;}
			
			if(numeros[0] > numeros[1] && numeros[0] > numeros[2]){
				if (Ui > 0){Ui++;}
			}
			else if(numeros[1] > numeros[0] && numeros[1] > numeros[2]){
				if(Ri > 0){Ri++;}
			}
			else if(numeros[2] > numeros[0] && numeros[2] > numeros[1]){
				if(Ii > 0){Ii++;}
			}
			
		}
		if(Ui == Ri || Ri == Ii || Ui == Ii){printf("URI\n");}
		else if(Ui > Ri && Ui > Ii){printf("Uilton\n");}
		else if(Ri > Ui && Ri > Ii){printf("Rita\n");}
		else if(Ii > Ui && Ii > Ri){printf("Ingred\n");}

		Ui = Ri = Ii = 0;
	}
	
	return 0;
}
