//output correto ,100% wo????

#include <bits/stdc++.h>
#define MAXN 102
using namespace std;

int grPremio[MAXN][MAXN];
int s[MAXN];
int pontos[MAXN];

int verifica(int,int);
void init();
void limpa(void);

int main(void)
{
	while(1)
	{
		int g,p;
		cin >> g >> p;

		if( g == 0 && p == 0) break;

		init();

		for(int i = 0;i < g;i++)
		{
			for(int j = 0;j < p;j++)
			{
				int coloc;
				cin >> coloc;

				grPremio[i][j] = coloc - 1; 
			}
		}

		int nSist;
		cin >> nSist;

		for(int i = 0;i < nSist;i++)
		{
			int ate;
			cin >> ate;

			for(int j = 0;j <ate;j++ )
			{
				int a;
				cin >> a;
				s[j] = a;
			}

			int maior = verifica(g,p);


			vector<int> champ;

			for(int i = 0;i < p;i++)
			{
				if(pontos[i] == maior)
				{
					champ.push_back(i + 1);
				}
			}

			for(int i = 0;i < (int)champ.size();i++)
			{
				if(i < (int)champ.size() - 1) printf("%d ",champ[i]);
				else printf("%d\n",champ[i]);
			}

			limpa();
		}

		//verifica(g,p);
	}

	return 0;
}


int verifica(int g,int p)
{
	int maior = 0;

	for(int i = 0;i < g;i++)
	{
		for(int k = 0;k < p;k++)
		{
			int coloc = grPremio[i][k];

			pontos[k] += s[coloc];

			if(pontos[k] > maior) maior = pontos[k];
		}
	}

	return maior;
}


void init()
{
	for(int i = 0;i < MAXN;i++)
	{
		s[i] = 0;
		pontos[i] = 0;

		for(int j = 0;j < MAXN;j++)
		{
			grPremio[i][j] = 0;
		}
	}
}


void limpa()
{
	for(int i = 0;i < MAXN;i++)
	{
		pontos[i] = 0;
	}
}