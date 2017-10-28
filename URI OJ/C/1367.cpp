#include <bits/stdc++.h>
#define TAM 27
using namespace std;

int tem[TAM];

void init();

int main(void)
{
	int t;

	while(1)
	{
		cin >> t;
		if(t == 0) break;

		init();

		char l;
		int time;
		string ver;
		int cor = 0,tempo = 0;

		for(int k = 0;k < t;k++)
		{
			cin >> l;
			cin >> time;
			cin >> ver;

			if(ver[0] == 'c')
			{
				cor++;
				tempo += time + tem[l-'A'];
			}
			else
			{
				tem[l-'A'] += 20;
			}
		}

		printf("%d %d\n",cor,tempo);
	}


	return 0;
}


void init()
{
	for(int u = 0;u < 26;u++)
	{
		tem[u] = 0;
	}
}