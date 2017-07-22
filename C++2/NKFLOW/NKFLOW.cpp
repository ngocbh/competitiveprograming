/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 1000 + 10;
const long MOD = 1000000000 + 7;
const long long oo = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <int,int> ii;

int n, m, s, t, delta;
int f[N][N], ta[N];
vector<ii> a[N];

bool findpath()
{
    memset(ta,0,sizeof ta);
    ta[s] = s;

    queue <ii> qu;
    qu.push(ii(s,oo));

    while ( !qu.empty() ) {
        int u = qu.front().first;
        int du = qu.front().second;
        qu.pop();

        if ( du == 0 ) continue;
        if ( u == t ) {
            delta = du;
            return true;
        }
        for (int i = 0; i < a[u].size(); i++) {
            int v = a[u][i].first;
            int uv = a[u][i].second;
            if ( ta[v] || uv == f[u][v] ) continue;
            qu.push(ii(v,min(du,uv-f[u][v])));
            ta[v] = u;
        }
    }

    return false;
}

void increaseflow()
{
    int u = t;
    while ( u != s) {

        f[ta[u]][u] += delta;
        f[u][ta[u]] -= delta;
        u = ta[u];
    }
}

int main()
{
    freopen("NKFLOW.inp","r",stdin);
    //freopen("NKFLOW.out","w",stdout);

    cin >> n >> m >> s >> t;

    for (int i = 1; i <= m; i++) {
        int u, v, uv;
        cin >> u >> v >> uv;
        a[u].push_back(ii(v,uv));
        a[v].push_back(ii(u,0));
    }

    while ( findpath() )
        increaseflow();

    LL ans = 0;
    for (int i = 0; i < a[s].size(); i++) {
        int v = a[s][i].first;
        if ( f[s][v] > 0 ) ans += f[s][v];
    }

    cout << ans;
}
