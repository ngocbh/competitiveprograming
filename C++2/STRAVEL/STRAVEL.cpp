/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 100000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n, m;
int ca[N], pa[N], d[N], res[N];
vector <ii> a[N];

void dijkstra_pa()
{
    priority_queue <ii,vector<ii>,greater<ii> > qu;
    qu.push(ii(0,1));
    for (int i = 1; i <= n; i++) d[i] = oo;
    d[1] = 0;

    while ( !qu.empty() ) {
        int u, du;
        du = qu.top().first;
        u = qu.top().second;
        qu.pop();
        if ( du != d[u] ) continue;
        for (int i = 0; i < a[u].size(); i++) {
            int v = a[u][i].first;
            int dv = a[u][i].second;
            if ( d[v] > du + dv ) {
                d[v] = du + dv;
                pa[v] = u;
                qu.push(ii(d[v],v));
            }
        }
    }
}

void dfs(int u,int par,int c)
{
    if ( par != pa[u] ) res[u] = min(res[u],c);

    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i].first;
        if ( !ca[v] ) continue;
        ca[v] = false;
        dfs(v,u,c+a[u][i].second);
        ca[v] = true;
    }
}

int main()
{
    freopen("STRAVEL.inp","r",stdin);
    //freopen("STRAVEL.out","w",stdout);
    ios::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        a[u].push_back(ii(v,c));
        a[v].push_back(ii(u,c));
    }

    dijkstra_pa();

    memset(ca,true,sizeof ca);
    ca[1] = false;
    for (int i = 1;i <= n; i++) res[i] = oo;
    dfs(1,0,0);

    for (int i = 2; i <= n; i++) {
        if ( res[i] != oo )
            cout << res[i] << endl;
        else
            cout << -1 << endl;
    }
}
