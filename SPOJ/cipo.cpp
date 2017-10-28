#include <bits/stdc++.h>
#define MAXN 1003
#define INF 0x3f3f3f
using namespace std;

int ma[MAXN][MAXN];
int dist[MAXN][MAXN];

void fW(int);

int main(void)
{
	int cip,pCip,contador = 0;
	//cin >> cip >> pCip;
	
	while(scanf("%d %d",&cip,&pCip) != EOF)
	{
		
		for(int u = 0;u < cip;u++)
		{
			for(int y = 0;y < cip;y++)
			{
				ma[u][y] = INF;
			}
		}


		for(int k = 0;k < pCip;k++)
		{
			int a,b,p;
			cin >> a >> b >> p;

			ma[a - 1][b - 1] = ma[b - 1][a - 1] = p;
		}

		
		for(int u = 0;u < cip;u++)
		{
			for(int y = 0;y < cip;y++)
			{
				dist[u][y] = ma[u][y];
			}
		}

		printf("Instancia %d\n",++contador);


		fW(cip);

		for(int i = 0;i < cip;i++)
		{
			for(int j = 0;j < cip;j++)
			{
				if(dist[i][j] == INF) cout << "'inf ";
				else cout << dist[i][j] << " ";
			}
			cout << endl;
		}

	}

	return 0;
}


void fW(int num)
{
	int k,i,j;

	for(k = 0;k < num;k++)
	{
		for(i = 0;i < num;i++)
		{
			for(j = 0;j < num;j++)
			{
				dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
			}
		}
	}
}