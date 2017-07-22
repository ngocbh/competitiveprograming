#include <bits/stdc++.h>

const long N = 10000 + 10;
using namespace std;

int n, m;
int ca[N], x[5], f[5][N];
vector <int> a[N];
bool b[N][N];

int main()
{   //freopen("TRAVEL12.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
        b[u][v] = true;
        b[v][u] = true;
    }

    for (int i = 1; i <= n; i++) {
        memset(ca,true,sizeof ca);
        for (int i = 1; i <= n; i++)
    }
}
