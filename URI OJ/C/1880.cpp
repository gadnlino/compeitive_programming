#include <bits/stdc++.h>

using namespace std;

vector<int> geraBase(int,int);
bool checa(vector<int>);

int main(void)
{
	int tc;
	cin >> tc;

	for(int i = 0;i < tc;i++)
	{
		int num;
		cin >> num;

		vector<int> solution;

		for(int base = 2;base <= 16;base++)
		{
			vector<int> decomp = geraBase(num,base);
			if(checa(decomp)) solution.push_back(base);
		}


		if(solution.empty()) printf("-1\n");
		else
		{
			for(int k = 0;k < (int)solution.size();k++)
			{
				if(k < (int)solution.size() - 1)printf("%d ",solution[k]);
				else printf("%d\n",solution[k]);
			}
		}
		
	}


	return 0;
}


vector<int> geraBase(int num,int base)
{	

	//printf("%d,%d\n",num,base);

	vector<int> decomp;

	while(num != 0)
	{
		int resto = num % base;
		num /= base;

		//printf("%d\n",resto);

		decomp.push_back(resto);
		
	}
	return decomp;
}


bool checa(vector<int> decomp)
{
	for(int i = 0;i < (int)decomp.size();i++)
	{
		int fin = decomp.size() - 1 - i;

		if(decomp[i] != decomp[fin]) return false;
	}

	return true;
}