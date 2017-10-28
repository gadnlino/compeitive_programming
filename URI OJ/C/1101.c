#include <stdio.h>
int main(void){
	int a = 1, b = 1, i;
	int temp, soma = 0;


	for(a,b; ; ){
		scanf("%d %d",&a,&b);
		if(a <= 0 || b <= 0) break;
		else{
			if(a > b){
				temp = a;
				a = b;
				b = temp;
			}

			for(i = a;i <= b;i++){
				printf("%d ",i);
				soma += i;
			}

			printf("Sum=%d\n",soma);
			soma = 0;

		}
		}


	return 0;
}
