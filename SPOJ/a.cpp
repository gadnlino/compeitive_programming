#include <bits/stdc++.h>
#define MAXN 53
using namespace std;

vector<int> la[MAXN];
vector<int> cities;
char colors[MAXN];
int dist[MAXN];

void bfs(int,int);

int main(void)
{
	for(int contador = 0;;contador++)
	{
		int cid,est,at,q;
		cin >> cid >> est >> at >> q;

		if(cid == est && cid == at && cid == q && q == 0) break;

		memset(colors,'w',cid);
		memset(dist,0,cid * sizeof(int));

		for(int k = 0;k < est;k++)
		{
			int a,b;
			cin >> a >> b;

			la[a - 1].push_back(b - 1);
			la[b - 1].push_back(a - 1);
		}

		bfs(at - 1,q);

		printf("Teste %d\n",contador + 1);
		
		sort(cities.begin(),cities.end());

		for(int i = 0;i < cities.size();i++)
		{
			printf("%d ",cities[i]);
		}
		printf("\n\n");

		cities.clear();

		for(int i = 0;i < cid;i++)
		{
			la[i].clear();
		}
	}

	return 0;
} 


void bfs(int s,int much)
{
	colors[s] = 'g';
	dist[s] = 0;

	queue<int> fila;
	fila.push(s);

	while(!fila.empty())
	{
		int u = fila.front();
		fila.pop();
		for(int k = 0;k < la[u].size();k++)
		{
			int i = la[u][k];

			if(colors[i] == 'w')
			{
				colors[i] = 'g';
				dist[i] = dist[u] + 1;
				if(dist[i] <= much)
				{
					cities.push_back(i + 1);
				}
				fila.push(i);
			}
		}

		colors[u] = 'b';
	}
}