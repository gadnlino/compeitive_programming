#include <bits/stdc++.h>
#define MAXN 203
#define TAM 40003
#define INF 0x3f3f3f
using namespace std;


//isso nao funciona
int matriz[MAXN][MAXN];
int cor[TAM];

void ini(void);
int confere(int,int);

int main(void)
{
	int h,l;
	cin >> h >> l;
	
	ini();

	for(int i = 0;i < h;i++)
	{
		for(int j = 0;j < l;j++)
		{
			cin >> matriz[i][j];
		}
	}	

	int x = confere(h,l);

	cout << x << endl;

	return 0;
}


int confere(int h,int l)
{
	int menor = INF;
	
	for(int i = 0;i < h;i++)
	{
		for(int j = 0;j < l;j++)
		{
			int x = matriz[i][j];
			
			if(cor[x] == INF) cor[x] = 1;

			//i-1 ,j
			if(i - 1 >= 0 && i - 1 < h)
			{
				if(j >= 0 && j < l)
				{
					if(matriz[i - 1][j] == x) cor[x]++;
				}
			}

			//i,j-1
			if(i >= 0 && i < h)
			{
				if(j - 1 >= 0 && j - 1 < l)
				{
					if(matriz[i][j - 1] == x) cor[x]++;
				}
			}

			//i,j+1
			if(i >= 0 && i < h)
			{
				if(j + 1 >= 0 && j + 1 < l)
				{
					if(matriz[i][j + 1] == x) cor[x]++;
				}
			}

			//i+1,j
			if(i + 1 >= 0 && i + 1 < h)
			{
				if(j >= 0 && j < l)
				{
					if(matriz[i + 1][j] == x) cor[x]++;
				}
			}
			printf("cor[%d] = %d\n",x,cor[x]);
		}
	}

	for(int u = 0;u < TAM;u++)
	{
		if(cor[u] < menor) menor = cor[u];
	}

	return menor;
}

void ini()
{
	for(int u = 0;u < TAM;u++)
	{
		cor[u] = 1;
	}
}