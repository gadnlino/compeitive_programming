#include <bits/stdc++.h>
#include <vector>
#define pb push_back

using namespace std;

vector<int> pontos;
vector<int> pontjog;
int main(){
  int jog,rod;
  scanf("%d %d",&jog,&rod);
  int i;
  int a;
  int soma;
  int j;
  int maior = 0;


  for(i = 0;i < jog * rod;i++){
    scanf("%d",&a);
    pontos.pb(a);
  }

  for(i = 0;i < jog;i++){
    soma = 0;
    for(j = 0;j < pontos.size();j++){
      if(j % jog == i){soma += pontos[j];}
    }
    pontjog.pb(soma);
  }

  for(i = 0;i < pontjog.size();i++){
    if(pontjog[i] >= maior){maior = i+1;}
  }
  printf("%d\n",maior);


  return 0;
}
