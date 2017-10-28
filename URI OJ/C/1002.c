#include <stdio.h>
int main(void){
	double A,
		   R;
	scanf("%lf",&R);    /*"lf" para declarar valores double(dupla precisão)*/
	
	A = 3.14159*R*R;
	
	printf("A=%1.4lf\n",A); /*notação "%lf\n" para apresentar o valor double */
	
	return 0;
	}
