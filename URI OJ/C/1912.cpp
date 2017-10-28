#include <bits/stdc++.h>
#define TAM 100007
using namespace std;

int tiras[TAM];
int qtd,area,contadorBs = 0;

float bs(float,float);

int main(void){
  int i,acum = 0;
  float answer,maior = 0;

  while(1){
    scanf("%d %d",&qtd,&area);
    if(qtd + area == 0){break;}

    for(i = 0;i < qtd;i++){scanf("%d",&tiras[i]);}

    for(i = 0;i < qtd;i++){
      if(tiras[i] > maior){maior = tiras[i];}
      acum += tiras[i];
    }

    if(acum == area){
      printf(":D\n");
    }
    else{
      answer = bs(0.0,maior);
      if(answer == -3){printf("-.-\n");}
      else{printf("%.4f\n",answer);}
    }
    acum = 0;
  }

  return 0;
}


float bs(float limi,float lims){
  contadorBs++;
  float acum = 0,meio = (limi + lims) / 2;
  int i;

  for(i = 0;i < qtd;i++){
    if((float)tiras[i] > meio){
      acum += tiras[i] - meio;
    }
  }

  if(acum == (float)area){return meio;}

  if(contadorBs == 30){
    contadorBs = 0;
    return -3;
  }

  if(acum > (float)area){
    return bs(meio,lims);
  }

  if(acum < (float)area){
    return bs(limi,meio);
  }
}
