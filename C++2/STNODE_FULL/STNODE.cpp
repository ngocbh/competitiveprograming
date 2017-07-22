#include <bits/stdc++.h>

const long N = 10000 + 10;
using namespace std;

int n, m, s, t;
int ca[N], d[N], inc[N];
vector <int> a[N];

void dfs(int u)
{
    if ( u == t ) {
        d[u] += 1;
        inc[u] += 1;
        return;
    }
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if ( !ca[v] ) continue;
        ca[v] = false;
        dfs(v);
        ca[v] = true;
        d[u] += inc[v];
        inc[u] += inc[v];
        inc[v] = 0;
    }
}

int main()
{   //freopen("STNODE.inp","r",stdin);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= n; i++) {
        int u , v;
        cin >> u >> v;
        a[u].push_back(v);
    }

    memset(ca,true,sizeof(ca));
    ca[s] = false;
    dfs(s);
    int ans = 0;
    for (int i = 1; i <= n; i++)    {
        if ( d[i] == d[t] && d[t] != 0 && i != t && i != s ) {
                ++ans;

        }
    }
    cout << ans;
}
