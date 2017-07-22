#include <bits/stdc++.h>

const long N = 1000000 + 10;
using namespace std;
typedef long long LL;
int n, m;
int a[N], ca[N], f[N];
int main()
{   freopen("CSP.inp","r",stdin);
    freopen("CSP.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i], ca[a[i]]++;

    for (int i = 1; i < N; i++)
        f[i] = f[i-1] + ca[i];

    LL ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += f[m-a[i]];
        if ( a[i] + a[i] <= m ) --ans;
    }

    cout << ans / 2;
}
