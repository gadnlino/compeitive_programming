#include <bits/stdc++.h>
#define MAXN 503
#define INF 0X3F3F3F
using namespace std;

int ma[MAXN][MAXN];
int dist[MAXN][MAXN];
int viz[MAXN][MAXN];

void fW(int);

int main(void)
{
	while(1)
	{
		int cid,ac;
		cin >> cid >> ac;

		if(cid == ac && ac == 0) break;

		for(int k = 0;k < cid;k++)
		{
			for(int y = 0;y < cid;y++)
			{
				if(k != y) ma[k][y] = INF;
				viz[k][y] = 0;
			}
		}

		for(int k = 0;k < ac;k++)
		{
			int a,b,p;
			cin >> a >> b >> p;

			ma[a -1][b-1] = p;
			viz[a - 1][b - 1] = 1;
		}

		for(int i = 0;i<cid;i++){
			for(int j =0;j<cid;j++){
				if(viz[i][j] and viz[j][i])
					ma[i][j] = ma[j][i] = 0;
			}
		}


		for(int k = 0;k < cid;k++)
		{
			for(int y = 0;y < cid;y++)
			{
				dist[k][y] = ma[k][y];
			}
		}

		fW(cid);

		int t;
		cin >> t;

		for(int i = 0;i < t;i++)
		{
			int a,b;
			cin >> a >> b;

			int x = dist[a - 1][b - 1]; 
			
			if(x == INF)
			{
				printf("Nao e possivel entregar a carta\n");
			}
			else
			{
				printf("%d\n",x);
			}
		}
		
		cout << endl;
	}

	return 0;
} 


void fW(int cid)
{
	int k,i,j;

	for(k = 0;k < cid;k++)
	{
		for(i = 0;i < cid;i++)
		{
			for(j = 0;j < cid;j++)
			{
				dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);		
			}
		}
	}
}