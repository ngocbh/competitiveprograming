#include <bits/stdc++.h>
#define cin fi
#define cout fo

using namespace std;
ifstream fi("MAGIC.inp");
ofstream fo("MAGIC.out");

typedef long long LL;
const long N = 2000 + 10;

int n, m;
LL ans = 0;
LL a[N][N], cl[N][N];
bool ok = true;
int h[5] = {-1,-1,1,1};
int c[5] = {-1,1,-1,1};

void dfs(int u,int v,int x)
{
    int aa;
    ans += 10;
    cl[u][v] = x;
    if ( a[u][v] && cl[u][v] != a[u][v] % 2 ) ok = false;
    for (int ui, vi, i = 0; i < 4; i++) {
        ui = u + h[i];
        vi = v + c[i];
        if ( ui >= 1 && ui <= n && vi >= 1 && vi <= m && cl[ui][vi] == -1 ) {
            dfs(ui,vi,1-x);
        }
    }
}

int main()
{
    //freopen("MAGIC.inp","r",stdin);
    //freopen("MAGIC.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j], cl[i][j] = -1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if ( a[i][j] && cl[i][j] == -1 ) {
                dfs(i,j,a[i][j]%2);
            }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if ( cl[i][j] == -1 ) {
                dfs(i,j,1);
            }

    if ( !ok ) { cout << -1; return 0; }

    for (int i = 1; i <= m; i++) cout << cl[1][i] << " ";
    if ( !a[1][1] )
        if ( cl[1][1] == 0 ) a[1][1] = 2;
        else a[1][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if ( a[i][j] ) {
                    if ( a[i][j] <= a[i-1][j] || a[i][j] <= a[i][j-1] ) { cout << -1; return 0; }
                    continue;
            }
            a[i][j] = max(a[i-1][j],a[i][j-1]) + 1;
            if ( a[i][j] % 2 != cl[i][j] )  ++a[i][j];
            if ( a[i+1][j] && a[i+1][j] <= a[i][j] ) { cout << -1; return 0; }
            if ( a[i][j+1] && a[i][j+1] <= a[i][j] ) { cout << -1; return 0; }
            if ( a[i+1][j+1] && a[i+1][j+1] <= a[i][j] ) { cout << -1; return 0; }
        }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans += a[i][j];

    cout << ans;
}
