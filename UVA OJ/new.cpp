#include <bits/stdc++.h>
#define MAXN 10000
#define INF 0X3F3F3F
using namespace std;

vector<int> la[MAXN];
int parents[MAXN];
int mark[MAXN];
int grau[MAXN];

void dfs(int);
void dfsVisit(int);

int main(void)
{
	int a,b,maior = 0;

	while(1)
	{
		memset(grau,0,MAXN * sizeof(int));

		while(cin >> a >> b)
		{
			//cin >> a >> b;
			if(a == b && a == 0) break;
			
			int x = max(a,b);
			if(x > maior) maior = x;
			
			la[a-1].push_back(b-1);
			grau[b-1]++;
		}

		if(a == -1 && a == b) break;

		for(int i = 0;i < maior;i++)
		{
			memset(mark,0,maior * sizeof(int));

			if(grau[i] == 0 && mark[i] == 0)
			{
				mark[i] = 1;
				dfsVisit(i);
			}
		}
	}

	return 0;
}

/*
void dfs(int nv)
{
	for(int i = 0;i < nv;i++)
	{
		if(mark[i] == 0)
		{
			mark[i] = 1;
			dfsVisit(i);
		}
	}
}
*/
void dfsVisit(int src)
{
	for(int u = 0;u < la[src].size();u++)
	{
		int v = la[src][u];
		if(mark[v] == 0)
		{
			parents[v] = src;
			mark[v] = 1;
			dfsVisit(v);
		}
	}
}