#include <bits/stdc++.h>
#define MAXN 10003
using namespace std;

vector<pair<int,int> > casos;

int main(void)
{
	int t;	
	cin >> t;
	
	for(int u = 0;u < t;u++)
	{
		int tc,num;
		cin >> tc >> num ;
		pair<int,int> par = make_pair(tc,num);
		casos.push_back(par);
	}
	
	for(int k = 0;k < casos.size();k++)
	{
		int sumpos = 0;
		int sume = 0;
		int sumo = 0;
		int tc = casos[k].first;
		int rc = casos[k].second;
		
		
		int cont = 0;
		for(int i = 1;cont < rc;i++,cont++)
		{
			sumpos += i;
		}
		
		cont = 0;
		for(int i = 1;cont < rc;i+= 2,cont++)
		{
			sumo += i;
		}
		
		cont = 0;
		for(int i = 2;cont < rc;i+= 2,cont++)
		{
			//cout <<"i = " <<  i << endl;
			sume += i;
		}
		
		printf("%d %d %d %d\n",tc,sumpos,sumo,sume);
	}
	
	
	return 0;
}
