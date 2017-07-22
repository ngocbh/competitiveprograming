#include <bits/stdc++.h>

using namespace std;

const long N = 300 + 10;
typedef pair <int,int> ii;

int n , t, x;
int p[N], ta[N], col[N], ca[N];
char a[N][N];

int dfs(int u)
{
    if ( ca[p[u]] ) x = min(x,p[u]);
    col[p[u]] = t;
    for (int v = 1; v <= n; v++)
        if ( a[u][v] == '1' && col[p[v]] != t ) {
            dfs(v);
        }
}

void solve()
{
    for (int k = 1; k <= n; k++)
        for (int u = 1; u <= n; u++)
            for (int v = 1; v <= n; v++)
                if ( a[u][k] == '1' && a[k][v] == '1' ) a[u][v] = '1';
    memset(col,0,sizeof col);

    for (int i = 1; i <= n; i++) a[i][i] = '1';

    for (int i = 1; i <= n; i++) {
        int x = N;
        for (int j = 1; j <= n; j++)
            if ( !col[p[j]] && a[i][j] == '1' )
                x = min(x,p[j]);
        cout << x << " ";
        col[x] = 1;
    }
}

int main()
{
    //freopen("B.inp","r",stdin);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) {
        scanf("%s", a[i] + 1);
    }

    solve();
    return 0;

    memset(ca,true,sizeof ca);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) if ( col[j] < 2 ) col[j] = 0;
        x = N;
        ++t, dfs(i);
        ca[x] = false;
        cout << x << " ";
    }

}
