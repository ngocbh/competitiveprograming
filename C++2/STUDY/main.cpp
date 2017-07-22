#include <bits/stdc++.h>

const long N = 100 + 10;
using namespace std;
int n, m;
int c[N][N];
int f[N][N], d[N];
int main()
{
    //freopen("STUDY.inp","r",stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> c[i][j];

    memset(f,0,sizeof(f));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            for (int o = 0; o <= j; o++)
                f[i][j] = max(f[i][j],f[i-1][o] + c[i][j-o]);
        }

    cout << f[n][m] << endl;

    //return 0;
    int u = n, v = m;
    while ( u != 0 ) {
        for (int i = 0; i <= v; i++)
            if ( f[u-1][i] + c[u][v-i] == f[u][v] ) {
                d[u] = v-i;
                --u;
                v = i;
                break;
            }
    }

    for (int i = 1; i <= n; i++) cout << d[i] << endl;
}
