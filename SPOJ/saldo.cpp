//maa = máximo até aqui    mta = maximo terminando aqui
#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int> > partidas;
vector<int> msc;

void procura(void);
void printa();

int main(void){
  int no;

  while(1)
  {
    scanf("%d",&no);
    if(no == 0) break;

    for(int i = 0;i < no;i++)
    {
      int a,b;
      scanf("%d %d",&a,&b);
      partidas.push_back(make_pair(a,b));
    }

    procura();

    printf("%d %d\n",++msc.back(),++msc.front());
    msc.erase(msc.begin(),msc.end());
    partidas.erase(partidas.begin(),partidas.end());
  }

  return 0;
}


void procura(){
  int i = 0,mta = 0,maa = 0,res;


  for(int j = 0;j < partidas.size();j++)
  {
    res = partidas[j].first - partidas[j].second;
    mta += res;

    if(mta <= 0){
      mta = 0;
    }

    if(maa < mta){
      maa = mta;
      msc.push_back(j);
    }
  }

}
