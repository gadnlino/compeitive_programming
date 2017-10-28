#include <stdio.h>
int main(void){
	int NUMBER,H;
	float MPH,SALARY;
	
	scanf("%d",&NUMBER);
	scanf("%d",&H);
	scanf("%f",&MPH);
	
	SALARY = MPH*H;
	
	printf("NUMBER = %d\n",NUMBER);
	printf("SALARY = U$ %1.2f\n",SALARY);
	
	return 0;
	
}
