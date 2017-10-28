#include <bits/stdc++.h>
#define MAXN 27
using namespace std;

vector<int> la[MAXN];
vector<int> ele;
int mark[MAXN];

int dfs(int);
void dfsVisit(int);

int main(void)
{
	int t,v,e;
	cin >> t;

	for(int i = 0;i < t;i++)
	{
		cin >> v >> e;

		memset(mark, 0 ,v * sizeof(int));

		for(int k = 0;k < e;k++)
		{
			char v1,v2;
			cin >> v1 >> v2;

			la[v1 - 'a'].push_back(v2 - 'a');
			la[v2 - 'a'].push_back(v1 - 'a');
		}

		printf("Case #%d:\n",i + 1);
		//cout << "Case #" << i + 1 << ":" << endl;
		
		int x = dfs(v);

		printf("%d connected components\n\n",x);
		//cout << x << " connected components" << endl << endl;

		for(int j = 0;j < v;j++)
		{
			la[j].clear();
		}
	}

	return 0;
}


int dfs(int nV)
{
	int comp = 0;

	for(int i = 0;i < nV;i++)
	{
		if(mark[i] == 0)
		{
			mark[i] = 1;
			dfsVisit(i);

			sort(ele.begin(),ele.end());

			for(int k = 0;k < ele.size();k++)
			{
				printf("%c,",ele[k] + 'a');
			}
			printf("\n");
			
			ele.clear();

			comp++;
		}
	}

	return comp;
}


void dfsVisit(int vertex)
{
	ele.push_back(vertex);

	for(int j = 0;j < la[vertex].size();j++)
	{
		int v = la[vertex][j];
		if(mark[v] == 0)
		{
			mark[v] = 1;
			dfsVisit(v);
		}
	}
}