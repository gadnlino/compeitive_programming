#include <stdio.h>
#include <math.h>

int main(void){
    float quantia;
    float n100,n50,n20,n10,n5,n2,m1,m50,m25,m10,m05,m01;

    scanf("%f",&quantia);
    n100 = floor(quantia / 100.00);
    quantia = fmodf(quantia,100.0);
    n50 = floor(quantia / 50.0);
    quantia = fmodf(quantia,50.0);
    n20 = floor(quantia / 20.0);
    quantia = fmodf(quantia,20.0);
    n10 = floor(quantia / 10.0);
    quantia = fmodf(quantia,10.0);
    n5 = floor(quantia / 5.0);
    quantia = fmodf(quantia,5.0);
    n2 = floor(quantia / 2.0);
    quantia = fmodf(quantia,2.0);
    m1 = floor(quantia / 1.0);
    quantia = fmodf(quantia,1.0);
    m50 = floor(quantia / 0.5);
    quantia = fmodf(quantia,0.5);
    m25 = floor(quantia / 0.25);
    quantia = fmodf(quantia,0.25);
    m10 = floor(quantia / 0.1);
    quantia = fmodf(quantia,0.1);
    m05 = floor(quantia / 0.05);
    quantia = fmodf(quantia,0.05);
    m01 = (quantia / 0.01);
    quantia = fmodf(quantia,0.01);

    printf("NOTAS:\n");
    printf("%.0f nota(s) de R$ 100.00\n",n100);
    printf("%.0f nota(s) de R$ 50.00\n",n50);
    printf("%.0f nota(s) de R$ 20.00\n",n20);
    printf("%.0f nota(s) de R$ 10.00\n",n10);
    printf("%.0f nota(s) de R$ 5.00\n",n5);
    printf("%.0f nota(s) de R$ 2.00\n",n2);
    printf("MOEDAS:\n");
    printf("%.0f moeda(s) de R$ 1.00\n",m1);
    printf("%.0f moeda(s) de R$ 0.50\n",m50);
    printf("%.0f moeda(s) de R$ 0.25\n",m25);
    printf("%.0f moeda(s) de R$ 0.10\n",m10);
    printf("%.0f moeda(s) de R$ 0.05\n",m05);
    printf("%.0f moeda(s) de R$ 0.01\n",m01);

	return 0;
}
