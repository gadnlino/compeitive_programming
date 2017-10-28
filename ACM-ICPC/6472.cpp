#include <bits/stdc++.h>
#define MAXN 100003

using namespace std;

//long long int pascalMatrix[MAXN][MAXN];

//void pascal(void);
long long int comb(long long int,long long int);

int main(void)
{
	int t;
	scanf("%d",&t);
	//pascal(MAXN);

	for(int i = 0;i < t;i++)
	{
		int b,c,d;

		long long int res = comb(c,d) ** b;

		printf("%d %lld\n",i + 1,res);
	}

	return 0;
}


int comb(int a,int b)
{
	
}