#include <bits/stdc++.h>
#define ii pair<int,int>
#define pip pair<int,ii>
#define MAXN 2003
#define INF 0x3f3f3f
#define st first
#define nd second
using namespace std;

vector<pip> el;
int dist[MAXN];

void bf(int,int);
bool relax(pip);

int main(void)
{
	int t;
	cin >> t;

	for(int j = 0;j < t;j++)
	{
		int v,e;
		cin >> v >> e;

		memset(dist,INF, v * sizeof(int));

		for(int i = 0;i < e;i++)
		{
			int a,b,p;
			cin >> a >> b >> p;
			ii par = make_pair(a,b);
			pip edge = make_pair(p,par);
			el.push_back(edge);
		}

		bf(rand() % v, v);

		el.clear();
	}

	return 0;
}


void bf(int src,int v)
{
	dist[src] = 0;

	for(int i = 0;i < v;i++)
	{
		for(int k = 0;k < el.size();k++)
		{
			relax(el[k]);
		}
	}

	for(int i = 0;i < el.size();i++)
	{
		if(relax(el[i]))
		{
			cout << "possible" << endl;
			return;
		}
	}

	cout << "not possible" << endl;
}


bool relax(pip edge)
{
	int w = edge.st;
	int u = edge.nd.st;
	int v = edge.nd.nd;

	if(dist[u] + w < dist[v])
	{
		dist[v] = dist[u] + w;
		return true;
	}

	return false;
}