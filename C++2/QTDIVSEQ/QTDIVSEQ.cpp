#include <bits/stdc++.h>

const long N = 1000000 + 10;
const long long MOD = 1000000000 + 7;

using namespace std;
typedef long long LL;

LL n , k;
LL a[N], sum[N], f[N];

LL pow_p(LL a,LL k,LL p)
{
    LL t = a, r = 1, tg = k;
    while ( tg > 0 ) {
        if ( tg % 2 == 1 ) r = (r*t) % p;
        t = (t*t) % p;
        tg /= 2;
    }
    return r;
}

LL calc(LL k,LL n)
{
    LL cur = 1;
    LL nn = n-k, kk = 0;

    for (int i = 1; i <= k; i++) {
        ++nn, ++kk;
        cur = ( ( (1LL*cur*nn % MOD ) * (pow_p(kk,MOD-2,MOD) % MOD) ) ) % MOD;
    }
    return cur;
}

int main()
{
    //freopen("QTDIVSEQ.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i], sum[i] = sum[i-1] + a[i];

    LL d = sum[n] / k;
    LL ans;
    if ( d != 0 ) {
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            if ( sum[i] % d == 0 ) {
                if ( sum[i] == 0 ) continue;
                if ( sum[i] / d == k && i != n ) continue;
                if ( sum[i] / d > k ) continue;
                if ( sum[i] / d <= 0 ) continue;
                f[sum[i]/d] = (f[sum[i]/d] + f[sum[i]/d-1]) % MOD;
            }
        }
        ans = f[k];
    }
    else {
        LL m = 0;
        for (int i = 1; i <= n; i++) if ( sum[i] == 0 ) ++m;
        ans = calc(k-1,m-1);
    }
    cout << ans;
}

