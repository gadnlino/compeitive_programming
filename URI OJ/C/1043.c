#include <stdio.h>
#include <stdlib.h>
int main(void){

  float A,B,C,perimetro,trapezio;

  scanf("%f %f %f",&A,&B,&C);

if(A > abs(B - C) && A < B + C){
  perimetro = A + B + C;
  printf("Perimetro = %.1f\n",perimetro);
}
else if(B > abs(A -C) && B < A + C){
  perimetro = A + B + C;
  printf("Perimetro = %.1f\n",perimetro);
}
else if(C > abs(A - B) && C < A + B){
  perimetro = A + B + C;
  printf("Perimetro = %.1f\n",perimetro);
}
else{
  trapezio = ((A + B)* C) / 2;
  printf("Area = %.1f\n",trapezio);
}
return 0;
}
