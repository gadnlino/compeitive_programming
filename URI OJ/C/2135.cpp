#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n,cont = 0,sum;
	
	while(scanf("%d",&n) != EOF)
	{
		sum = 0;
		vector<int> conj;
		vector<int> solve;
		set<int> tes;

		for(int u = 0;u < n;u++)
		{
			int a;
			cin >> a;
			sum += a;
			conj.push_back(a);
			tes.insert(a);
		}

		for(int u = conj.size();u >= 0;u--)
		{
			printf("sum = %d\n",sum);
			if(tes.find(sum) != tes.end())
			{
				solve.push_back(sum);
			}
			sum -= conj[u];
		}

		for(int i = 0;i < solve.size();i++)
		{
			printf("%d ",solve[i]);
		}
		cout << "\n";

		printf("Instancia %d\n",++cont);

		if(solve.empty())
		{
			cout << "nao achei\n";
		}
		else printf("%d\n",solve.front());

		cout << "\n";
	}


	return 0;
}