#include <stdio.h>
#define DIM 12
int main(void){
    int linha;
     char operacao;
     float matriz[DIM][DIM];
     int i, j;
     float resultado;

     scanf("%d" , &linha);
     getchar();     
     scanf("%c", &operacao);


    for(i = 0 ; i < DIM ; i++){
        for(j = 0 ; j < DIM ; j++){
            scanf("%f", &matriz[i][j]);
            }
        }

     switch (operacao) {
        case 'S':
            for (j = 0 ; j < DIM ; j++){
                resultado += matriz[linha][j];
                }
                break;
        case 'M':
            for(j = 0 ; j < DIM ; j++){
                resultado += matriz[linha][j];
            }
            resultado /= DIM;
            break;
     }

    printf("%.1f\n", resultado);

    return 0;
}
