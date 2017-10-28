#include <bits/stdc++.h>
#define INF 0x3f3f3f
using namespace std;

pair<int,int> array[INF];

int bfs(pair<int,int>);

int main(void)
{
	/*
	pair<int,int> root = make_pair(1,1);
	bfs(root);
	*/
	
	int t;
	cin >> t;
	
	for(int r = 0;r < t;r++)
	{	int tc,n = 0,d = 0;
		string str;
		cin  >> tc;
		cin >> str;
		
		for(int i = 0;i < str.length();i++)
		{
			if(isdigit(str[i]) && n == 0) n = str[i]- '0';
			else d = str[i] - '0';
		}
		printf("%d %d\n",n,d);
		pair<int,int> esse = make_pair(n,d);
		
		int index = bfs(esse);
		
		printf("%d %d\n",tc,index);
	}
	
	return 0;
}


int bfs(pair<int,int> esse)
{
	int cont = 1;
	
	queue<pair<int,int> > fila;
	
	pair<int,int> root = make_pair(1,1);
	
	fila.push(root);
	
	while(!fila.empty())
	{
		pair<int,int> comp = fila.front();
		fila.pop();
		
		if(comp.first == esse.first && comp.second == esse.second) return cont;
		
		int nume1 = comp.first;
		int denon1 = nume1 += comp.second;
		
		pair<int,int> par1 = make_pair(nume1,denon1);
		fila.push(par1);
		
		int nume2 = denon1;
		int denon2 = nume1;
		
		pair<int,int> par2 = make_pair(nume2,denon2);
		fila.push(par2);
		cont++;
	}
}
