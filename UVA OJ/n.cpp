#include <bits/stdc++.h>
#define MAXN 10000
#define INF 0x3f3f3f
#define ii pair<int,int>
using namespace std;

int group[MAXN];
int tam[MAXN];
vector<ii> edges;

void uniao(int,int);
int find(int);

int main(int argc, char const *argv[])
{
	int cont = 0;
	while(1)
	{
		int a,b,maior = 0;
		set<int> usados;

		while(scanf("%d %d",&a,&b) && (a != 0 && b != 0))
		{
			if(a == -1 && b == -1) return 0;

			int x = max(a,b);
			if(x > maior) maior = x;
			
			if(usados.find(a-1) == usados.end()) usados.insert(a-1);
			if(usados.find(b-1) == usados.end()) usados.insert(b-1);
			
			edges.push_back(make_pair(a-1,b-1));
		}

		printf(" maior = %d\n",maior);

		for(int y = 0;y < maior;y++)
		{
			if(usados.find(y) != usados.end())
			{
				group[y] = y;
				tam[y] = 1;
			}
			else
			{
				group[y] = INF;
			}
		}

		for(int i = 0;i < edges.size();i++)
		{
			int u = edges[i].first;
			int v = edges[i].second;

			uniao(u,v);
		}

		for(int i = 0;i < maior;i++)
		{
			printf("group[%d] = %d\n",i,group[i]);
		}

		set<int> res;

		for(int i = 0;i < maior;i++)
		{
			if(group[i] == i) res.insert(i);
		}

		if(res.size() == 1 || res.empty())
		{
			printf("Case %d is a tree\n",++cont);
		}
		else printf("Case %d is not a tree\n",++cont);

		edges.clear();
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
		tam[b] += tam[a];
		group[a] = b;
	}
}

int find(int a)
{
	if(a == group[a]) return a;

	return group[a] = find(group[a]);
}