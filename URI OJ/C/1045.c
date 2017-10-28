#include <stdio.h>

int main(void){

  double a, b, c;
  int temp1, temp2,temp3;

  scanf("%lf %lf %lf",&a,&b,&c);

  if(a < b){
    temp1 = a;
    a = b;
    b = temp1;
  }
  if(b < c){
    temp2 = b;
    b = c;
    c = temp2;
  }
  if(a < b){
    temp3 = a;
    a = b;
    b = temp3;
  }

  if(a >= b + c){
    printf("NAO FORMA TRIANGULO\n");
  }
  else if(a * a == b * b + c * c){
    printf("TRIANGULO RETANGULO\n");
  }
  else if(a * a < b * b + c * c){
    printf("TRIANGULO ACUTANGULO\n");
  }
  else if(a * a > b * b + c * c){
    printf("TRIANGULO OBTUSANGULO\n");
  }
  if(a == b && b == c){
    printf("TRIANGULO EQUILATERO\n");
  }
  else if(a == b || b == c){
    printf("TRIANGULO ISOSCELES\n");
  }
return 0;
}
