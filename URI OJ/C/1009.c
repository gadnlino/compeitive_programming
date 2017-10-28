#include <stdio.h>
int main (void){
    char NOME;
    double SALARIO,VENDAS,TOTAL;

    scanf("%s",&NOME);
    scanf("%lf",&SALARIO);
    scanf("%lf",&VENDAS);

    TOTAL = SALARIO + VENDAS*0.15 ;

    printf("TOTAL = R$ %1.2lf\n",TOTAL);

    return 0 ;
}
