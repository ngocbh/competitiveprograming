#include <bits/stdc++.h>

const long N = 5000 + 10;
using namespace std;
int n, m;
int ans = 0;
int ca[N];
vector <int> a[N];

void dfs(int u)
{
    ca[u] = false;
    int v = 0;

    for (int i = 0; i < a[u].size(); i++) {
        v = a[u][i];
        if ( !ca[v] && v != u ) ++ans;
        else
           if ( ca[v] ) dfs(v);
    }
}

int main()
{  // freopen("ADS.inp","r",stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    memset(ca,true,sizeof(ca));
    for (int i = 1; i <= n; i++) {
        if ( !ca[i] ) continue;
        dfs(i);
    }
    cout << ans - m ;
}

