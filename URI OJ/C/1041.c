#include <stdio.h>
int main(void){

	float X,Y;

	scanf("%f %f",&X ,&Y);

	if(X > 0 && Y > 0){
		printf("Q1\n");
	}
	else if(X > 0 && Y < 0){
		printf("Q4\n");
	}
	else if (X < 0 && Y < 0){
		printf("Q3\n");
	}
	else if (X < 0 && Y > 0 ){
		printf("Q2\n");
	}
	else if(X == 0 || Y == 0){
    if(X == 0 && Y != 0){
		printf("Eixo Y\n");
    }
    if(Y == 0 && X != 0){
      printf("Eixo X\n");
    }
    if(X == 0 && Y == 0){
      printf("Origem\n");
    }
	}
return 0;
}
