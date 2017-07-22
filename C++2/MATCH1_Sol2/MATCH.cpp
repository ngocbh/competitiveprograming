#include <bits/stdc++.h>

using namespace std;

const long N = 100000 + 10;

int n, m;
int col[N], ca[N], flag, match[N];
vector <int> a[N];

int dfs(int u)
{
    if ( col[u] == flag ) return 0;
    col[u] = flag;

    for (int i = 0; i < a[u].size(); i++)
    {
        int v = a[u][i];
        if ( !match[v] || dfs(match[v] ) ) {
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

int main()
{
    //freopen("MATCH1.inp","r",stdin);

    cin >> n >> m;
    int u, v;
    while ( scanf("%d %d", &u, &v) > 0 )
        a[u].push_back(v);

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ++flag, ans += dfs(i);

    cout << ans << endl;
    for (int i = 1; i <= m; i++) {
        int j = match[i];
        if ( j ) cout << j << " " << i << endl;
    }
}
