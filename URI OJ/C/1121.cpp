//incompleto

#include <bits/stdc++.h>
#define MAXN 102
using namespace std;

vector<string> arena;
int posx,posy,n,m;
int fig;

void move();
void escolhe(char);
void verifica(int,int);

int main(void)
{
	int inst;
	while(1)
	{
		cin >> n >> m >> inst;
		if(n == 0 && m == 0 && inst == 0) break;

		fig = 0;

		for(int i = 0;i < n;i++)
		{
			string line;
			cin >> line;
			arena.push_back(line);
		}


		for(int i = 0;i < (int)arena.size();i++)
		{
			for(int j = 0;j < (int)arena[i].length();j++)
			{
				char ch = arena[i][j];
				if(ch == 'O' || ch == 'L' || ch == 'N' || ch == 'S')
				{
					posx = i;
					posy = j;
				}
			}
		}

		string str;

		cin >> str;


		for(int i = 0;i < (int)str.length();i++)
		{
			escolhe(str[i]);
			
			//cout << endl;
			/*
			for(int j = 0;j < n;j++)
			{
				for(int y = 0;y < m;y++)
				{
					printf("%c ",arena[j][y]);
				}
				printf("\n");
			}
			*/
		}

		printf("%d\n",fig);

		arena.clear();
	} 


	return 0;
}


void escolhe(char c)
{
	switch (c)
	{
		case 'D':
			if(arena[posx][posy] == 'O')
			{
				//printf("oeste -> norte\n");
				arena[posx][posy] = 'N';
				break;
			}
			if(arena[posx][posy] == 'L')
			{
				//printf("leste -> sul\n");
				arena[posx][posy] = 'S';
				break;
			}
			if(arena[posx][posy] == 'S')
			{
				//printf("sul -> oeste\n");
				arena[posx][posy] = 'O';
				break;
			}
			if(arena[posx][posy] == 'N')
			{
				//printf("norte -> leste\n");
				arena[posx][posy] = 'L';
				break;
			}
		case 'E':
			if(arena[posx][posy] == 'O')
			{
				//printf("oeste -> sul\n");
				arena[posx][posy] = 'S';
				break;
			}
			if(arena[posx][posy] == 'L')
			{
				//printf("leste -> norte\n");
				arena[posx][posy] = 'N';
				break;
			}
			if(arena[posx][posy] == 'S')
			{
				//printf("sul -> leste\n");
				arena[posx][posy] = 'L';
				break;
			}
			if(arena[posx][posy] == 'N')
			{
				//printf("norte -> oeste\n");
				arena[posx][posy] = 'O';
				break;
			}
		case 'F':
			move();
			break;
	}
}


void move()
{
	switch(arena[posx][posy])
	{
		case 'N':
			verifica(posx-1,posy);
			break;
		case 'S':
			verifica(posx+1,posy);
			break;
		case 'L':
			verifica(posx,posy+1);
			break;
		case 'O':
			verifica(posx,posy-1);
			break;
	}
}


void verifica(int x,int y)
{
	if(x >= 0 && x < n && y >= 0 && y < m)
	{
		//printf("maoeee\n");
		if(arena[x][y] != '#')
		{
			if(arena[x][y] == '*') fig++;

			char ch = arena[posx][posy];
			arena[posx][posy] = '.';

			posx = x;
			posy = y;
			arena[posx][posy] = ch;
		}
	}
}