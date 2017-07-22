#include <bits/stdc++.h>

const long N = 10000 + 10;
using namespace std;

int n , m;
int d[N], lad[N], low[N], num[N], child[N], khop[N];
vector <int> a[N];

void dfs(int u)
{
    num[u] = ++num[0];
    low[u] = num[u];

    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if ( v == lad[u] ) continue;

        if ( num[v] ) {
            low[u] = min(low[u] , num[v]);
        }
        else {
            lad[v] = u;
            dfs(v);
            low[u] = min(low[u] , low[v]);
        }
    }
}

int main()
{
    freopen("GRAPH_.inp","r",stdin);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if ( !num[i] ) dfs(i);
    }

    int anskhop = 0, anscau = 0;

    for (int i = 1; i <= n; i++) {
        int v = lad[i];
        if ( v > 0 ) ++child[v];
    }

    for (int i = 1; i <= n; i++) {
        int u = lad[i];
        if ( u > 0 && lad[u] > 0 && low[i] >= num[u] ) khop[u] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if ( lad[i] == 0 && child[i] >= 2) khop[i] = 1;
    }

    for (int i = 1; i <= n; i++)
        anskhop += khop[i];

    for (int i = 1; i <= n; i++) {
        if ( lad[i] != 0 && low[i] >= num[i] ) ++anscau;
    }

    cout << anskhop << " " << anscau;

}
