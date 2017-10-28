#include <stdio.h>

long long int bigMod(long long int base,long long int ex,long long int mod);

int res = 1;

int main(void){
  long long int b,e,mod;

  while(scanf("%lld %lld %lld",&b,&e,&mod) != EOF){

    getchar();
    getchar();
    printf("%lld\n",bigMod(b,e,mod));
    res = 1;
  }
  return 0;
}


long long int bigMod(long long int base,long long int ex,long long int mod){
  while(ex){
    if(ex % 2){
      res = (res * base) % mod;
      base = (base * base) % mod;
      ex = (ex -1 ) / 2;
    }
    else{
      base = (base * base) % mod;
      ex /= 2;
    }
  }
  return res;
}
