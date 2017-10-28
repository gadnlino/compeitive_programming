#include <bits/stdc++.h>
#define MAXN 102

using namespace std;

vector<int> la[MAXN];
int grau[MAXN];
vector<int> ordt;

int main(void)
{
    while(1)
    {
        int v,e;
        scanf("%d %d",&v,&e);
        if((v == e) && (e == 0)) break;

        memset(grau,0,v * sizeof(int));

        for(int k = 0;k < e;k++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            la[a - 1].push_back(b - 1);
            grau[b - 1]++;
        }

        for(int i = 0;i < v;i++)
            if(!grau[i])
                ordt.push_back(i);

        for(int a = 0;a < ordt.size();a++)
        {
            int v = ordt[a];
            for(int i = 0;i < la[v].size();i++)
            {
                int o = la[v][i];
                grau[o]--;
                if(grau[o] == 0)
                {
                    ordt.push_back(o);
                }
            }
        }

        for(int a = 0;a < ordt.size();a++)
        {
            printf("%d ",ordt[a] + 1);
        }

        printf("\n");

        for(int q = 0;q < v;q++)
        {
            la[q].clear();
        }

        ordt.clear();
    }


    return 0;
}
