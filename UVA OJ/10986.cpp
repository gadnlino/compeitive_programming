#include <bits/stdc++.h>
#define ii pair<int,int>
#define MAXN 20003
#define INF 0x3f3f3f
using namespace std;

vector<ii> la[MAXN];
int dist[MAXN];

void dijkstra(int);

int main(void)
{
    int tc;
    cin >> tc;

    for(int y = 0;y < tc;y++)
    {
        int v,e,s,t;
        cin >> v >> e >> s >> t;

        for(int i = 0;i < v;i++)
        {
            dist[i] = INF;
        }

        for(int i = 0;i < e;i++)
        {
            int a,b,p;
            cin >> a >> b >> p;

            ii par = make_pair(b,p);
            la[a].push_back(par);

            par = make_pair(a,p);
            la[b].push_back(par);
        }

        dijkstra(s);


        printf("Case #%d: ",y+1);

        if(dist[t] != INF) printf("%d\n",dist[t]);
        else printf("unreachable\n");

        for(int i = 0;i < v;i++)
        {
            la[i].clear();
        }
    }

    return 0;
}


void dijkstra(int src)
{
    dist[src] = 0;

    set<ii> bin;

    ii par = make_pair(dist[src],src);
    bin.insert(par);

    while(!bin.empty())
    {
        //extract min
        ii min = *(bin.begin());
        int u = min.second;
        int ud = min.first;

        bin.erase(bin.begin());

        for(int i = 0;i < la[u].size();i++)
        {
            int v = la[u][i].first;
            int vw = la[u][i].second;

            if(ud + vw < dist[v])
            {
                ii parb = make_pair(dist[v],v);

                dist[v] = ud + vw;
                ii para = make_pair(dist[v],v);

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