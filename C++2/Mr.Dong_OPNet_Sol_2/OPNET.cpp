#include <bits/stdc++.h>

const long N = 100 + 10;
const long long inf = 10000000000 + 7;

using namespace std;
typedef pair<int,int> ii;
typedef long long LL;

int n, m , K;
int a[N][N];
int f[(1<<18)+1][21][19];

LL calc(int t,int i,int k)
{
    if ( f[t][i][k] != -1 ) return f[t][i][k];

    if ( t == ((1<<(n-2)) - 1) ) {
        f[t][i][k] = a[i][2];
        return a[i][2];
    }
    LL best = inf;
    for (int j = 3; j <= n; j++)
        if ( ((t>>(j-3)) & 1) == 0 && k < K ) {
            LL tmp = a[i][j] + calc(t|(1<<(j-3)),j,k+1);
            if ( tmp < best ) best = tmp;
        }
    if ( k > 0 ) {
        LL tmp = a[i][2] + calc(t,1,0);
        if ( tmp < best ) best = tmp;
    }
    f[t][i][k] = best;
    return best;
}

int main()
{
    freopen("OPNET.inp","r",stdin);
    freopen("OPNET.out","w",stdout);

    cin >> n >> m >> K;
    for (int i = 0; i <= (1<<18); i++)
        for (int j = 0; j <= 20; j++)
            for (int k = 0; k <= 18; k++)
                f[i][j][k] = -1;

    for (int i = 1; i  <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = inf;

    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        a[u][v] = c;
        a[v][u] = c;
    }

    cout << calc(0,1,0);
}
