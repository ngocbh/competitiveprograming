#include <bits/stdc++.h>

const long N = 100 + 10;
using namespace std;
typedef long long LL;

int n, m;
LL low[N], num[N], d[N], ca[N], lad[N], f[N];
vector <int> a[N];
stack <int> s;

void dfs(int u)
{
    num[u] = ++num[0];
    low[u] = N;
    f[u] = 1;

    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if ( v == lad[u] ) continue;
        if ( num[v] ) {
            low[u] = min(low[u],num[v]);
        }
        else {
            lad[v] = u;
            dfs(v);
            low[u] = min(low[u],low[v]);
            f[u] += f[v];
        }
    }

}

int main()
{   freopen("WEATHER.inp","r",stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
        if ( !num[i] )
            dfs(i);

    LL ans = 0;
    for (int i = 1; i <= n; i++)
        if ( lad[i] != 0 && low[i] >= num[i] ) {

                int u , v, x, y;
                u = i; v = lad[i];

                ans += f[u] * ( n - f[u] );
                cout << u << " " << v << " " << f[2] << endl;
        }

    cout << ans;
}
