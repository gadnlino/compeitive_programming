#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

int memo[MAXN];

int factorial(int);

int main(){
  int i,num,quantosNums = 0;
  
  cin >> num;

  quantosNums = 0;

  memset(memo,0,num * sizeof(int));

  for(i = 0;i <= num;i++)
  {
  	int j = factorial(i);
  	memo[i] = j;

  	if(j >= num) break;
  }

  int quanto = num;

  while(quanto > 0)
  {
  	int j = memo[i];

  	if(j > quanto)
  	{
  		i--;
  	}
  	else
  	{
  		quantosNums += quanto / j;
  		quanto = quanto % j;
  	}
  }

  cout << quantosNums << endl;
  
  return 0;
}


int factorial(int x)
{
	if(x == 0 || x == 1)
	{
		return 1;
	}

	if(memo[x-1]) return x * memo[x - 1];
	
	return x * factorial(x - 1);
}
