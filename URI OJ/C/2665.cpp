#include <bits/stdc++.h>
#define MAXN 0X3F3F3F
using namespace std;

typedef struct PONTO
{
    long long int x,y;
}ponto;

bool compare(ponto p1,ponto p2);
double pit(double,double);
double angulo(double,double);
int calcula(int,double,double);

vector<ponto> arr;
int xroot1,xroot2,qtdMax;

int main()
{
    int t;
    scanf("%d %d %d",&t,&xroot1,&xroot2);

    for(int i = 0;i < t;i++)
    {
        ponto p;
        scanf("%lld %lld",&p.x,&p.y);
        arr.push_back(p);
    }

    sort(arr.begin(),arr.end(),compare);
    // int quantos  = calcula(1,angulo((double)xroot2 - (double)arr[0].x,(double)arr[0].y),angulo((double)arr[0].x - (double)xroot1,(double)arr[0].y));
    int quantos = calcula(0,MAXN,MAXN);
    printf("%d\n",qtdMax);

    return 0;
}

bool compare(ponto p1,ponto p2)
{
    return (p1.y > p2.y);
}

double pit(double c1,double c2)
{
    return sqrt(c1 * c1 + c2 * c2);
}

double angulo(double c1,double c2)
{
  return acos(c1 / pit(c1,c2));
}


int calcula(int id,double mdir,double mesq)
{
  int quantos = 1;
  bool dentro = false;

  if(id == (int)arr.size()) return 0;
  // quantos = max(1,1 + calcula(i+1,angDir,angEsq));

  double angDir = angulo((double)xroot2 - (double)arr[id].x,(double)arr[id].y);
  double angEsq = angulo((double)arr[id].x - (double)xroot1,(double)arr[id].y);

  if(angDir < mdir && angEsq < mesq)
  {
      // printf("entrei %lld,%lld\n\n",arr[id].x,arr[id].y);
      quantos++;
      mdir = angDir;
      mesq = angEsq;
  }

  qtdMax = max(quantos,calcula(id+1,mdir,mesq));

  return quantos;

  /*
  for(int i = id;i < (int)arr.size()-1;i++)
  {
    double angDir = angulo((double)xroot2 - (double)arr[i].x,(double)arr[i].y);
    double angEsq = angulo((double)arr[i].x - (double)xroot1,(double)arr[i].y);
    printf("ponto %lld,%lld\n",arr[i].x,arr[i].y);

    if(angDir < mdir && angEsq < mesq)
    {
      dentro = true;
      printf("entrei %lld,%lld\n\n",arr[i].x,arr[i].y);
    }
    calcula(i+1,angDir,angEsq);

  }
  */

  return quantos;
}
