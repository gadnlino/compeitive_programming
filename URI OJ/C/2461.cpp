#include <bits/stdc++.h>

using namespace std;

set<int> conja,conjb;

int confere(int);

int main(void)
{
	int a,b;
	cin >> a >> b;

	for(int i = 0;i < a;i++)
	{
		int k;
		cin >> k;
		conja.insert(k);
	}

	for(int i = 0;i < b;i++)
	{
		int k;
		cin >> k;

		conjb.insert(k);
		
		if(conja.find(k) != conja.end())
		{
			continue;
		}
		else
		{
			if(conjb.size() > 1 && confere(k))
			{
				cout << k << endl;
				return 0;
			}
		}
	}

	cout << "sim" << endl;

	return 0;
} 


int confere(int num)
{
	int erro = 0;

	for(int i = 0;i < conjb.size();i++)
	{
		std::set<int>::iterator it = conjb.begin();
		std::advance(it,i);
		int f = *it;
		//cout << "f = " << f << endl;
		//cout << "num = " << num << endl;
		
		if(conjb.find(num - f) != conjb.end())
		{
			//cout << "ah bem" << endl;
			return 0;
		}
		else
		{
			//cout << "ah caralho" << endl;
			erro = 1;
		}
	}

	return erro;
}