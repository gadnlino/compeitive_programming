#include <bits/stdc++.h>
#define INF 0X3F3F3F
using namespace std;

vector<int> tams;

int main(void)
{
	int people,paes,maior = -INF,pedAtual,lim = INF;

	cin >> people;
	cin >> paes;

	for(int k = 0;k < paes;k++)
	{
		int a;
		cin >> a;
		tams.push_back(a);
		if(a > maior) maior = a;
	}

	for(int q = maior;q > 0 ;q--)
	{
		pedAtual = 0;

		for(int u = 0;u < tams.size();u++)
		{
			pedAtual += tams[u] / q;
		}

		if(pedAtual >= people)
		{
			lim = q;
			break;
		}
	}

	printf("%d\n",lim);

	return 0;
}
