#include <bits/stdc++.h>

const long N = 100000 + 10000;
const long long MOD = 1000000000 + 7;

using namespace std;
typedef long long LL;

int n, m, c;
LL up[N], low[N], cup[N], clow[N], cr[N], res[N], dp[N/100][N/100], sum[N/100][N/100];

int main()
{   //freopen("KSPHERES.inp","r",stdin);
    cin >> n >> m >> c;

    for (int i = 1; i <= n; i++) {
        cin >> up[i];
        ++cup[up[i]];
    }

    for (int i = 1; i <= m; i++) {
        cin >> low[i];
        ++clow[low[i]];
    }

    int sz = 0;
    for (int i = 1; i <= c; i++)
        if ( cup[i] > 0 && clow[i] > 0 )
            cr[++sz] = (1LL*cup[i]*clow[i]) % MOD;

    for (int i = 1; i <= sz; i++) sum[0][i] = (sum[0][i-1] + cr[i]) % MOD;

    for (int  i = 1; i <= c; i++) {
        for (int j = 1; j <= sz+1; j++)
            {
                dp[i][j] = (1LL*sum[i-1][j-1]*cr[j]) % MOD;
                sum[i][j] = (sum[i][j-1] + dp[i][j]) % MOD;
            }
    }

    for (int  i = 1; i <= c; i++) {
        res[i] = sum[i][sz];
    }

    for (int i = 1; i <= c; i++) cout << res[i] << " ";
}
