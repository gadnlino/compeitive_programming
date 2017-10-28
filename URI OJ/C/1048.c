#include <stdio.h>
int main(void){
    float salario;
    float novoSalario;
    float reajuste;

    scanf("%f",&salario);

    if(salario >= 0 && salario <= 400){
        reajuste = 0.15;
        novoSalario = salario + salario * reajuste;
    }
    else if(salario >= 400 && salario <= 800){
        reajuste = 0.12;
        novoSalario = salario + salario * reajuste;
    }
    else if(salario >= 800 && salario <= 1200){
        reajuste = 0.1;
        novoSalario = salario + salario * reajuste;
    }
    else if(salario >= 1200 && salario <= 2000){
        reajuste = 0.07;
        novoSalario = salario + salario * reajuste;
    }
    else if(salario > 2000){
        reajuste = 0.04;
        novoSalario = salario + salario * reajuste;
    }
    printf("Novo salario: %.2f\n",novoSalario);
    printf("Reajuste ganho: %.2f\n",reajuste * salario);
    printf("Em percentual: %.0f %%\n",reajuste * 100);

	return 0;
}
