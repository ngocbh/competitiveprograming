#include <bits/stdc++.h>

const long N = 10000 + 10;
using namespace std;
typedef long long LL;
int n, m , s, t;
int ca[N], cb[N], inc[N], muti[N],d[N];
vector <int> a[N];

void dfs(int u)
{
    if ( u == t ) {
        d[u] += 1;
        inc[u] += 1;
        return;
    }

    for (int i = 0; i < a[u].size(); i++) {
            int v;
            v = a[u][i];
            if ( !ca[v] && !cb[v] ) continue;
            if ( !ca[v] && cb[v] ) {
                d[u] += d[v];
                inc[u] += d[v];
                ++muti[v];
                continue;
            }
            ca[v] = false;
            cb[v] = false;
            dfs(v);
            cb[v] = true;
            d[u] += inc[v];
            inc[u] += inc[v];
            inc[v] = 0;
    }

}

void dfs_muti(int u)
{
    if ( u == t ) return;

    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if ( !cb[v] )  continue;
        cb[v] = false;
        muti[v] += muti[u];
        dfs_muti(v);
    }
}

int main()
{   freopen("STNODE.inp","r",stdin);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)    ca[i] = true , cb[i] = true, muti[i] = 0;
    ca[s] = false; cb[s] = false; muti[s] = 1;

    dfs(s);

    dfs_muti(s);

    for (int i = 1; i <= n; i++) {
        cout << muti[i] << " " << d[i] << endl;
        d[i] = d[i] * muti[i];

    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cout << i << " -> " << d[i] << " " << endl;
        if ( i != s && i != t && d[i] == d[t] ) ++ans;
    }
    cout << ans ;
}
