#include <bits/stdc++.h>

using namespace std;



int main(){
  int jog,prt;
  scanf("%d %d",&jog,&prt);
  int i,j;
  int plan[jog][prt];
  int qts = 0;
  int conf;

  for(i = 0;i < jog;i++){
    for(j = 0;j < prt;j++){
      scanf("%d",&plan[i][j]);
    }
  }

  for(i = 0;i < jog;i++){
    conf = 1;
    for(j = 0;j < prt;j++){
      if(plan[i][j] == 0){conf = 0;}
    }
    if(conf != 0){qts++;}
  }

  printf("%d\n",qts);

  return 0;
}
