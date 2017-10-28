#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int p;
    scanf("%d",&p);

    map<int,int> fila;
    int cont = 0;
    vector<int> num;

    for(int i = 0;i < p;i++)
    {
        int c;
        scanf("%d",&c);
        num.push_back(c);
        fila[c] = cont++;
    }

    int r;
    scanf("%d",&r);

    for(int i = 0;i < r;i++)
    {
        int c;
        scanf("%d",&c);

        if(fila.find(c) != fila.end())
        {
            fila[c] = -1;
            p--;
        }
    }

    map<int,int>::iterator it = fila.begin();
    /*
    for(;it != fila.end();++it)
    {
        pair<int,int> par = *it;

        printf("%d -> %d\n",par.first,par.second);
    }
    */
    cont = 0;

    for(int i = 0;i < (int)num.size();i++)
    {
        if(fila[num[i]] >= 0)
        {
            cont < p - 1 ? printf("%d ",num[i]) : printf("%d\n",num[i]);
            cont++;
        }
    }

    return 0;
}
