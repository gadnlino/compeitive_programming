#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

vector<int> la[MAXN];
map<long long int,int> mapa;
int grau[MAXN];
int usado[MAXN];
int mark[MAXN];
int olhou,v,vis;

void dfs(int);
void init(void);
void limpa(void);

int main(void)
{
	int contCasos = 0;

	while(true)
	{

		long long int n1,n2;

		init();

		int cont = 0;
		v = 0;

		while(true)
		{
			//scanf("%d %d",&n1,&n2);

			scanf("%lld %lld",&n1,&n2);

			if(n1 == 0 && n2 == 0) break;
			if(n1 < 0 && n2 < 0) return 0;
			
			if(mapa.find(n1) != mapa.end())
			{
				if(mapa.find(n2) != mapa.end())
				{
					la[mapa[n1]].push_back(mapa[n2]);
					grau[mapa[n2]]++;
				}
				else
				{
					mapa[n2] = cont++;
					la[mapa[n1]].push_back(mapa[n2]);
					grau[mapa[n2]]++;
					v++;
				}
			}
			else
			{
				mapa[n1] = cont++;
				if(mapa.find(n2) != mapa.end())
				{
					la[mapa[n1]].push_back(mapa[n2]);
					grau[mapa[n2]]++;
					v++;
				}
				else
				{
					mapa[n2] = cont++;
					la[mapa[n1]].push_back(mapa[n2]);
					grau[mapa[n2]]++;
					v += 2;
				}
			}

			usado[mapa[n1]] = usado[mapa[n2]] = 1;
			/*
			cout << "c1" << " " << n1 << " " << mapa[n1] << endl;
			cout << "c2" << " " << n2 << " " << mapa[n2] << endl;
			*/
		}
		
		/*cout << v << endl;
		
		for(int i = 0;i < MAXN;i++)
		{
			
			if(usado[i])
			{
				printf("%d -> ",i);
				for(int j = 0;j < la[i].size();j++)
				{
					printf("%d ",la[i][j]);
				}
				printf("\n");
			}
		}
		printf("\n");
		*/

		vector<int> zeros;
		bool is = true;

		for(int i = 0;i < MAXN;i++)
		{
			if(!grau[i] && usado[i]) zeros.push_back(i);
		}

		//olhou = 0;
		if(!v) is = true;
		else if(zeros.empty()) is = false;
		else
		{
			for(int i = 0;i < (int)zeros.size();i++)
			{
				//printf("Main src = %d\n",zeros[i]);
				//memset(mark,0,MAXN * sizeof(int));
				mark[zeros[i]] = 1;
				vis = olhou = 0;
				dfs(zeros[i]);

				limpa();
				//printf(" vis = %d\n",vis);
				if(olhou || vis != v) is = false;
			}
		}


		//if(olhou) is = false;

		is? printf("Case %d is a tree.\n",++contCasos)
		: printf("Case %d is not a tree.\n",++contCasos);


		for(int i = 0;i < MAXN;i++)
		{
			la[i].clear();
		}
		
		mapa.clear();
	}

	return 0;
}


void dfs(int src)
{
	vis++;

	for(int i = 0;i < (int)la[src].size();i++)
	{
		int dst = la[src][i];
		//printf("dst = %d,mark ? %d\n",dst,mark[dst]);

		if(!mark[dst])
		{
			
			mark[dst] = 1;
			dfs(dst);
		} 
		else
		{
			olhou = 1;
			dfs(dst);
		}
	}
}


void init()
{
	for(int i = 0;i < MAXN;i++)
	{
		grau[i] = usado[i] = mark[i] = 0;
	}
}

void limpa()
{
	for(int i = 0;i < MAXN;i++)
	{
		mark[i] = 0;
	}
}