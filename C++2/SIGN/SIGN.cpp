#include <bits/stdc++.h>

const long N = 500 + 10;
const long long oo = (int)1e9+7;
using namespace std;
typedef long long LL;
int n, m;
LL f[N][N], a[N][N];

int main()
{   freopen("SIGN.inp","r",stdin);
    //freopen("SIGN.out","w",stdout);

    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    for (int i = 1
         ; i <= m+1; i++)
        for (int j = 0; j <= n+1; j++)
            f[i][j] = oo*oo;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            f[i][j] = min(f[i-1][j],f[i][j-1]) + a[i][j];

    for (int i = 1; i <= m; i++)
        for (int j = n; j >= 1; j--)
            f[i][j] = min(f[i][j],min(f[i-1][j],f[i][j+1]) + a[i][j]);

    LL ans = oo*oo;
    for (int i = 1; i <= n; i++) ans = min(ans,f[m][i]);
    cout << ans;
}
