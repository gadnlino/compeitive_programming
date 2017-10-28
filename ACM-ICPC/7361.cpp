#include <bits/stdc++.h>
#define MAXN 0x3f3f3f
#define MOD 1000000000
using namespace std;
 
//long long unsigned int memo[MAXN];
 
long long int unsigned fib(long long unsigned int);
 
int main(void)
{
    int t;
    cin >> t;
    /*int x =  281474976710656 % MOD;
    long long int fx = fib(x);
    printf("%d  %lld\n",x,fx);*/
    
 
    for(int y = 0;y < t;y++)
    {
        int tc;
        long long unsigned int num;
        cin >> tc >> num;
 
        long long unsigned int sol = fib(num);
 
        printf("%d %lld\n",tc,sol);
 
    }
     
    return 0;
}
 
 
long long unsigned int fib(long long unsigned int num)
{
    //printf("%d\n",num);
    if(num == 0) return 1;
    if(num == 1 || num == 2) return 1;
     
   // if(memo[num]) return memo[num];
     
     unsigned long long int x;
    if(num % 2)
    {
        long long unsigned int k = (num + 1) / 2;
        x = (fib(k) * fib(k) + fib(k-1) * fib(k-1)) % MOD;
    }
    else
    {
        long long unsigned int k = num/2;
        x = ((2 * fib(k-1) + fib(k))* fib(k)) % MOD;
    }
     
   return x;
}
