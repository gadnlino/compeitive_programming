//falta corrigir o getline

#include <bits/stdc++.h>
#include <string>
#define MAXN 1000
#define ii pair<int,int>
#define st first
#define nd second
using namespace std;

int tam[MAXN];
int gr[MAXN];

void unir(int,int);
int find(int);
void init(int);
vector<int> recognize(string);

int main(void)
{
	bool trigger = false;
	int tc,i = 0;
	scanf("%d",&tc);

	while(i < tc)
		{	
			i++;

			if(trigger) break;

			string str;
			int v,sA = 0,uA = 0;
			scanf("%d",&v);
			getchar();

			init(v);

			while(1)
			{
				//printf("cai aqui\n");
				getline(cin,str);

				if(str.empty())
				{
					//printf("oi\n");
					/*
					if(i == tc - 1)
					{
						printf("oi2\n");
						trigger = true;
					}
					*/
					break;
				}

				//if(str.empty() && trigger) return 0;

				if(str[0] == 'c')
				{
					vector<int> edge;
					edge = recognize(str);

					int v1 = edge[0];
					int v2 = edge[1];

					//printf("%d %d \n",v1,v2);

					unir(v1 - 1,v2 - 1);
				}

				if(str[0] == 'q')
				{
					vector<int> edge;
					edge = recognize(str);

					int v1 = edge[0];
					int v2 = edge[1];

					//printf("%d %d \n",v1,v2);

					int f1 = find(v1 - 1);
					int f2 = find(v2 - 1);

					if(f1 == f2) sA++;
					else uA++;
				}
				
			}

			if(i < tc) printf("%d,%d\n\n",sA,uA);
			else printf("%d,%d\n",sA,uA);
		}

	return 0;
}


void unir(int a,int b)
{
	a = find(a);
	b = find(b);

	if(tam[a] >= tam[b])
	{
		gr[b] = a;
		tam[a] += tam[b];
	}
	else
	{
		gr[a] = b;
		tam[b] += tam[a];
	}
}

int find(int a)
{
	if(a == gr[a]) return a;

	return gr[a] = find(gr[a]);
}

void init(int v)
{
	for(int i = 0;i < v;i++)
	{
		gr[i] = i;
		tam[i] = 1;
	}
}


vector<int> recognize(string str)
{
	vector<int> edge;

	for(int i = 1;i < (int)str.length();i++)
	{
		if(isdigit(str[i]))
		{
			int v = str[i] - '0';
			edge.push_back(v);
		}
		
	}

	return edge;
}