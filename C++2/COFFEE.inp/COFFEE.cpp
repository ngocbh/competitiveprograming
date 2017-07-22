#include <bits/stdc++.h>

const long N = 200 + 10;
using namespace std;
typedef long long LL;

LL n, k, d , m;
LL a[N];
LL f[N][N], sum[N];

int main()
{   //freopen("COFFEE.inp","r",stdin);
 int t;
 cin >> t;
 while ( t-- ) {
    cin >> n >> k >> d >> m;

    memset(sum,0,sizeof(sum));
    for (int i = 1; i <= n; i++)
        cin >> a[i], sum[i] = sum[i-1] + a[i];

    memset(f,0,sizeof(f));
    for (int i = 1; i <= n+1; i++)
        f[1][i] = sum[i-1];

    for (int i = 2; i <= k + 1; i++) {
        for (int j = i; j <= n+1; j++) {
                if ( i == k+1 && j <= n ) continue;
                if ( i <= k && j == n+1 ) continue;
                for (int o = i-1; o < j; o++) {
                    if ( o + d < j ) {
                        f[i][j] = max(f[i][j], f[i-1][o] + (sum[o+d] - sum[o]) * m + sum[j-1] - sum[o+d] );
                    }
                    else
                        f[i][j] = max(f[i][j], f[i-1][o] + ( sum[j-1] - sum[o] ) * m );
                }
        }
    }
    cout << f[k+1][n+1] << endl;

 }
}
