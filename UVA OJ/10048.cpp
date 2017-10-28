#include <bits/stdc++.h>
#define MAXN 103
#define INF 0x3f3f3f
#define ii pair<int,int>
#define sii set<ii>
using namespace std;

vector<pair<int,int> > la[MAXN];
int dist[MAXN];
int maxi[MAXN];

void dijkstra(int);

int main(void)
{
	int cont = 0;

	int cros,s,q;

	while(1)
	{
		cin >> cros >> s >> q;

		if(cros == s && s == q && q == 0) break;

		for(int i = 0;i < s;i++)
		{	
			int a,b,p;

			cin >> a >> b >> p;
			la[a - 1].push_back(make_pair(b - 1 ,p));
			la[b - 1].push_back(make_pair(a - 1 ,p));
		}
		
		printf("Case #%d\n",++cont);

		for(int i = 0;i < q;i++)
		{
			memset(dist,INF,cros * sizeof(int));
			memset(maxi,0,cros * sizeof(int));

			int a,b;

			cin >> a >> b;
			
			dijkstra(a - 1);

			for(int t = 0;t < cros;t++)
			{
				printf("%d ",maxi[t]);
			}
			cout << endl;

			if(dist[b-1] != INF) printf("%d\n",dist[b-1]);
			else printf("no path\n");
		}

		cout << endl;

		for(int u = 0;u < cros;u++)
		{
			la[u].clear();
		}
	}

	return 0;
}


void dijkstra(int a)
{
	dist[a] = 0;

	sii bin;

	bin.insert(make_pair(dist[a],a));

	while(!bin.empty())
	{
		ii par = *bin.begin();
		int u = par.second;		

		printf("src = %d,src dist = %d\n",u+1,dist[u]);

		bin.erase(*bin.begin());
		
		for(int i = 0;i < la[u].size();i++)
		{
			int v = la[u][i].first;
			int vw = la[u][i].second;
			printf("dest = %d ,w = %d\n",v+1,vw);

			if(vw > maxi[v]) maxi[v] = vw;

			if(dist[u] + vw < dist[v])
			{
				ii parb = make_pair(dist[v],v);

				dist[v] = dist[u] + vw;

				ii para = make_pair(dist[u] + vw,v);

				if(bin.find(parb) != bin.end())
				{
					bin.erase(parb);
					bin.insert(para);
				}
				else
				{
					bin.insert(para);
				}
			}
		}
	}
}