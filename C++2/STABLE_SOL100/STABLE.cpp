#include <bits/stdc++.h>

const long N = 10000 + 10;
const long oo = 100000000 + 10;
using namespace std;
typedef pair <int,int> ii;

int n, m, s;
int d[N], ca[N], f[N];
vector <int> a[N];
ii p[N*10];

void dijkstra()
{
    priority_queue <ii,vector<ii>,greater<ii> > qu;

    memset(ca,true,sizeof ca);
    for (int i = 1; i <= n; i++) d[i] = oo;
    d[s] = 0;
    qu.push(ii(0,s));
    ca[s] = false;

    while ( !qu.empty() ) {
        int u,du,v;
        u = qu.top().second;
        du = qu.top().first;
        qu.pop();
        if ( du != d[u] ) continue;

        for (int i = 0; i < a[u][i]; i++) {
            int v = a[u][i];
            if ( !ca[v] ) continue;
            if ( d[v] > d[u] + 1 ) {
                d[v] = d[u] + 1;
                ca[v] = false;
                qu.push(ii(d[v],v));
            }
        }
    }
}

void dfs(int u,int c)
{
    ca[u]++;
    for (int i = 0; i < a[u][i]; i++) {
        int v = a[u][i];
        if ( c + 1 != d[v] ) continue;
        if ( ca[v] ) f[v] = true;
        if ( ca[v] == 2 ) continue;
        dfs(v,c+1);
    }
}

int main()
{
    //freopen("STABLE.inp","r",stdin);

    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        cin >> p[i].first >> p[i].second;
    }

    sort(p+1,p+m+1);
    for (int i = 1; i <= m; i++) {
        if ( p[i].first == p[i-1].first && p[i].second == p[i-1].second ) continue;
        a[p[i].first].push_back(p[i].second);
    }

    for (int i = 1; i <= n; i++) a[i].push_back(0);

    dijkstra();

    memset(ca,0,sizeof(ca));
    memset(f,false,sizeof f);
    dfs(s,0);

    int ans = 0;
    for (int i = 1; i <= n; i++) if ( f[i] && i != s ) {
            ++ans;
    }
    cout << ans;

}
