#include <bits/stdc++.h>

const long N = 1000000*2 + 10;
const long long MOD = 1000000000 + 7;
using namespace std;
typedef long long LL;

int t;
int n, d;
LL ans, res;
int a[N], sum[N], p[N];

int rem, c, nn, mu;
inline void solve(int n,int d)
{
    rem = 0;
    for (int i = 1; i <= n; i++) {
        c = d*d + rem;
        a[i] = c % 10;
        rem = c / 10;
    }

    nn = n;
    if ( rem )
        a[++n] = rem;

    sum[0] = 0;
    for (int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i];

    rem = 0;
    mu = nn*2;
    if ( d*d < 9 ) --mu;
    if ( d == 3 && n == 1 ) mu = 1;

    for (int i = 1; i <= nn; i++) {
        c = sum[i] + rem;
        rem = c / 10;
        c = c % 10;
        ans = ( ans + 1LL * p[mu--] * c ) % MOD;

    }

    for (int i = 1; i <= nn; i++) {
        c = sum[n] - sum[i] + rem;
        rem = c / 10;
        c = c % 10;
        ans = ( ans + 1LL * p[mu--] * c ) % MOD;

    }

    cout << ans << endl;


}

int main()
{   //freopen("FSTSQ.inp","r",stdin);
    ios::sync_with_stdio(0);

    cin >> t;

    p[1] = 1;
    for (int i = 2; i < N - 5; i++) p[i] = (1LL * p[i-1] * 23) % MOD;

    while ( t-- ) {
        cin >> n >> d;
        ans = 0;
        solve(n,d);
        //navie(n,d);
    }


}
