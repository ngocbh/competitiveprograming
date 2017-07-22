#include <bits/stdc++.h>

const long N = 10000 + 10;
const long oo = 1000000000 + 10;
using namespace std;
typedef pair <int> ii;
int n, m, k, s1, s2, t;
vector <int> a[N];
vector <ii> gta[N];
int l[N], r[N], res1[N], res2[N], ca[N];


void dijkstra(int res[],int s,int t)
{
        priority_queue <ii,vector<ii>,greater<ii> > qu;
        qu.push(ii(s,0));
        int d[N];
        for (int i = 1; i <= n; i++ ) d[i] = oo;
        d[s] = 0;
        while ( true ) {
                int u,v,du,uv;
                u = qu.top().first;
                du = qu.top().second;
                qu.pop();
                if ( du != d[u] ) continue;
                for (int i = 0; i < a[u].size(); i++) {
                            v = a[u][i];
                            if ( gta[u][i].second == 0 ) {
                                    uv = gta[u][i].first;
                            }
                            else {
                                    uv = 0;
                            }
                            if ( d[v] > d[u] + uv ) {
                                    d[v] = d[u] + uv;
                                    trace[v] = u;
                                    qu.push(ii(v,d[v]));
                            }
                }
        }

}
int main()
{       freopen("HACK.inp","r",stdin);
        cin >> n >> m >> k;
        cin >> s1 >> s2 >> t;
        for (int i = 1; i <= m; i++) {
                int u , v, c;
                cin >> u >>  v >> c;
                a[u].push_back(v);
                gta[u].push_back(ii(c,0);
        }
        for  (int  i = 1; i <= k; i++ ) {
                int u, v, c1, c2;
                cin >> u >> v >> c1 >> c2;
                a[u].push_back(v);
                gta[u].push_back(ii(c1,c2));
        }
        for (int i = 1; i <= n; i++ ) {
                a[i].push_back(0);
                gta[i].push_back(ii(0,0));
        }
        dijkstra();
}

