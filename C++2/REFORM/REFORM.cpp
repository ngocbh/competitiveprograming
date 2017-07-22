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

int n, m, inter, cau;
int num[N], low[N], ca[N], d[N], pa[N], f[N], ter[N];
ii M[N*2];
vector<int> a[N];

int dfs(int u,int par)
{
    int c = 1;
    low[u] = num[u] = ++num[0];


    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if ( v == par ) continue;
        if ( num[v] ) {
            low[u] = min(low[u],num[v]);
        }
        else {
            pa[v] = u;
            c += dfs(v,u);
            low[u] = min(low[u],low[v]);
        }
    }

    if ( low[u] == num[u] ) {
        if ( pa[u] != 0 ) ++cau;
    }
    f[u] = c;
    return c;
}

int main()
{
    //freopen("REFORM.inp","r",stdin);
    //freopen(".out","w",stdout);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if ( !num[i] )
            ++inter, ter[inter] = dfs(i,0);
    }

    LL ans = 0;

    if ( inter > 2 ) {
        cout << 0;
        return 0;
    }

    if ( inter == 2 ) {
        cout << 1LL*(m-cau)*ter[1]*ter[2];
        return 0;
    }

    ans = 1LL*(m-cau)*( 1LL*n*(n-1)/2 - m );

    for (int i = 1; i <= n; i++) {
        if ( pa[i] == 0 ) continue;
        if ( low[i] == num[i] ) {
            ans += 1LL*f[i]*(n-f[i]) - 1;
        }
    }

    cout << ans;
    return 0;
}
