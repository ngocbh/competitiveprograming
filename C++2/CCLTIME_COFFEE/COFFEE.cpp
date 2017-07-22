#include <bits/stdc++.h>

const long N = 5000 + 10;
using namespace std;
typedef long long LL;

int n, k , d, m, sum = 0;
int f[N][N], a[N];
int main()
{       freopen("COFFEE.inp","r",stdin);
    int t;
    cin >> t;
    while (t--) {
    cin >> n >> k >> d >> m;
    sum = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];

    for (int i = 1; i <= n; i++) f[1][i] = a[i];
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= n; j++) f[i][j] = 100000000;

    for (int i = 2;  i <= k; i++) {
        for (int j = i; j <= n; j++) {
                for (int o = i-1; o < j; o++) {
                    f[i][j] = min(f[i][j], f[i-1][o] + a[j]);
                }
                //cout << f[i][j] << " ";
        }
    }

    LL ans = 0;

    for (int i = k; i <= n; i++) {
        if ( i < n-d )
            ans = max(ans,1LL*(sum-f[k][i]));
        else
            ans = max(ans,1LL*(sum-f[k][i])*m);
    }
    cout << ans << endl;
    }
}
