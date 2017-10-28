#include <stdio.h>
#include <string.h>
#define MAXN 20000
#define INF 0X3F3F3F

typedef struct PAR
{
	int st;
	int nd;
}PAR;

int tam[MAXN];
int group[MAXN];
PAR question[MAXN];

void uniao(int,int);
int find(int);

int main(void)
{
	int t,contq,i,v;
	char str[100],op;
	int a,b,q,e,sA,uA;

	scanf("%d",&t);
	
	getchar();

	for(i = 0;i < t;i++)
	{
		contq = 0;
		sA = uA = 0;

		getchar();

		scanf("%d",&v);
		getchar();

		for(q = 0;q < v;q++)
		{
			group[q] = q;
			tam[q] = 1;
		}
		/*
		int k;
		k = getchar();
		k -= '0';
		printf("k = %d\n",k);*/

		while((op = getchar()) && op != '\n' && getchar())
		{
			/*getchar();
			op = getchar();
			if((char)op == '\n') break;
			getchar();
			*/

			a = getchar();
			getchar();

			b = getchar();
			getchar();

			a -= '0';
			b -= '0';

			printf("%d %d\n",a,b);

			if(op == 'q')
			{
				printf("oi\n");
				question[contq].st = a ;
				question[contq++].nd = b;
			}

			if(op == 'c')
			{
				printf("eu te odeio\n");
				uniao(a,b);
			}
		}

		/*getchar();*/
		
		int tr;
		for(tr = 0;tr < v;tr++)
		{
			printf("group[%d] = %d\n",tr+1,group[tr]);
		}

		int cr;
		for(cr = 0;cr < contq;cr++)
		{
			printf("u = %d v = %d\n",question[cr].st+1,question[cr].nd+1);
		}

		for(e = 0;e < contq;e++)
		{
			if(find(question[e].st) == find(question[e].nd))
			{
				sA++;
			}
			else
			{
				uA++;
			}
		}

		printf("%d,%d\n",sA,uA);

		printf("\n");

		getchar();
	}

	return 0;
}


int find(int a)
{
	if(a == group[a]) return a;

	group[a] = find(group[a]);

	return group[a];
}


void uniao(int a,int b)
{
	a = find(a);
	b = find(b);

	if(tam[a] >= tam[b])
	{
		tam[a] += tam[b];
		group[b] = a;
	}
	else
	{
		tam[b] += tam[a];
		group[a] = b;
	}
}