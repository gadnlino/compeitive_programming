#include <bits/stdc++.h>
#define MAXN 10000
using namespace std;

int group[MAXN];
int tam[MAXN];

void uniao(int,int);
int find(int);

int main(void)
{
	int t;
	cin >> t;

	for(int i = 0;i < t;i++)
	{
		char ch;
		cin >> ch;
		
		int v = ch - 'A' + 1;

		for(int s = 0;s < v;s++)
		{
			group[s] = s;
			tam[s] = 1;
		}

		getchar();

		string str;

		while(getline(cin,str))
		{
			if(!str.length()) break;

			int a = str[0] - 'A';
			int b = str[1] - 'A';

			uniao(a,b);
		}

		set <int> bin;
		int cont = 0;
		
		for(int q = 0;q < v;q++)
		{
			int x = find(q);
			
			if(bin.find(x) == bin.end())
			{
				bin.insert(x);
				cont++;
			}
		}

		if(i < t-1)printf("%d\n\n",cont);
		else printf("%d\n",cont);

		//cout << endl;
	}

	return 0;
}


void uniao(int a,int b)
{
	a = find(a);
	b = find(b);

	if(tam[a] >= tam[b])
	{
		group[b] = a;
		tam[a] += tam[b];
	}
	else
	{
		group[a] = b;
		tam[b] += tam[a];
	}
}


int find(int a)
{
	if(a == group[a]) return a;

	return group[a] = find(group[a]);
}