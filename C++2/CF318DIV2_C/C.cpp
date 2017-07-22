#include <bits/stdc++.h>

const long N = 4000 + 10;
using namespace std;
typedef long long LL;
int n, m, x[4], ca[N], cf[N][N], f[N];
LL ans;
vector <int> a[N];

void ktkq()
{
    LL res = 0;
    for (int i = 1; i <= 3; i++) res += f[x[i]];
    if ( cf[x[1]][x[2]] == 1 ) res -= 2;
    if ( cf[x[2]][x[3]] == 1 ) res -= 2;
    if ( cf[x[1]][x[3]] == 1 ) res -= 2;
    ans = min(ans,res);
}

void dfs(int ci)
{
    if ( ci >= 3 ) {
        ktkq();
        return;
    }
    int u = x[ci], v;
    ca[x[ci]] = false;
    for (int i = 0; v = a[u][i]; i++)
        if ( ca[v] ){
        if ( ci == 2 ) if ( cf[x[1]][v] == 0 ) continue;
        x[ci+1] = v;
        dfs(ci+1);
    }
}

int main()
{   //freopen("C.inp","r",stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        cf[u][v] = 1;
        a[v].push_back(u);
        cf[v][u] = 1;
        ++f[u];
        ++f[v];
    }
    ans = (int) (1e16);
    for (int i = 1; i <= n; i++) a[i].push_back(0);

    for (int i = 1; i <= n; i++) {
        memset(ca,true,sizeof(ca));
        x[1] = i;
        dfs(1);
    }
    if ( (int) (1e16) == ans ) cout << -1;
    else cout << ans;
}
