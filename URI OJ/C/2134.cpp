#include <bits/stdc++.h>
#define MAXN 103

using namespace std;

typedef struct ALUNO
{
	int nota;
	string nome;
}ALUNO;

ALUNO turma[MAXN];


bool compare(ALUNO,ALUNO);

int main(void)
{
	int t,cont = 0;

	while(scanf("%d",&t) != EOF)
	{
		for(int j = 0;j < t;j++)
		{
			cin >> turma[j].nome;
			cin >> turma[j].nota;
		}

		for(int i = 0;i < t;i++)
		{
			//cout << "ai " << endl;
			for(int j = 0;j < t - 1 - i;j++)
			{
				//cout << "ueu " << endl;
				if(compare(turma[j],turma[j+1]))
				{
					/*cout << "oi " << endl;
					cout << turma[j].nome << " " << turma[j+1].nome << endl;*/
					ALUNO temp = turma[j+1];
					turma[j+1] = turma[j];
					turma[j] = temp;
				}
			}
		}
		/*
		for(int y = 0;y < t;y++)
		{
			cout << turma[y].nome << " " << turma[y].nota << endl;
		}
		*/
		cout << "Instancia " << ++cont << endl;
		cout << turma[t-1].nome << endl;
		cout << "\n";
	}

	return 0;
}


bool compare(ALUNO x,ALUNO y)
{
	if(x.nota < y.nota)
	{
		return true;
	}
	else if((x.nota == y.nota ) && (x.nome > y.nome))
	{
		return true;
	}
	else return false;
	//return ((x.nota > x.nota) || ((x.nota == y.nota) && (x.nome < y.nome)));
}