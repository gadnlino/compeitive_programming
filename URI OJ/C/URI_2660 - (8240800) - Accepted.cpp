#include<cstdio>
#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>

using namespace std;

unsigned long long int mdc(int,int);

int main(){
	int num,limit;
	scanf("%d %d",&num,&limit);

	vector<int> ciclos;
	for(int i = 0;i < num;i++)
	{
		int p;
		scanf("%d",&p);
		ciclos.push_back(p);
	}

	int mmc = ciclos[0];

	for(int i = 1;i < (int)ciclos.size();i++)
	{
			mmc = (mmc / (mdc(mmc,ciclos[i]))) * ciclos[i] ;
			//printf("mmc = %d\n",mmc);
	}

	int maior = mmc;
	int esc = 1;

	for(int i  = 1;i <= limit;i++)
	{
		unsigned long long int mmc2 = (mmc / mdc(mmc,i)) * i;
    // printf("%d --%d-> %llu\n",mmc,i,mmc2);

		if(maior < mmc2 && mmc2 <= limit)
		{
			//printf(" i =%d --mmc = %d\n",i,mmc2);
			maior = mmc2;
			esc = i;
		}
		else if(mmc2 == maior){}
	}

	printf("%d\n",esc);

	return 0;
}



unsigned long long int mdc(int a,int b)
{
		if(b == 0) return a;
		return mdc(b,a % b);
}
