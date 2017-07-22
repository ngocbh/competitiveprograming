#include <bits/stdc++.h>
//#define cin fi
//#define cout fo

using namespace std;

//ifstream fi("GCDLCM.inp");
//ofstream fo("GCDLCM.out");

typedef long long LL;
const long N = 1000000 + 10;
const long MOD = 1000000000 + 9;

int n, m, k;
LL a[N], p[N], q[N], ntq[N], ntp[N];
vector <int> prime;

LL Pow(LL a,LL b,LL c)
{
    LL t = a, r = 1, tg = b;
    while ( tg > 0 ) {
        if ( tg % 2 == 1 ) r = (r*t) % MOD;
        t = (t*t) % MOD;
        tg /= 2;
    }
    return r;
}

void init()
{
    for (int i = 2; i < N; i++) {
        if ( a[i] ) continue;
        a[i] = i;
        for (int j = i; j < N; j += i)
            if ( !a[j] ) a[j] = i;
    }
    a[1] = 0;
}

int main()
{
    //freopen("GCDLCM.inp","r",stdin);
    //freopen("GCDLCM.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k;

    if ( m == 1 && n == 1 && k == 1 ) {
        int a, b;
        cin >> a >> b;
        if ( a == b ) cout << 1;
        else cout << 0;
        return 0;
    }

    init();

        for (int x, i = 1; i <= m; i++) {
            cin >> x;
            while ( a[x] != 0 && x % a[x] == 0 ) ++p[a[x]], x /= a[x];
        }

        for (int x, i = 1; i <= n; i++) {
            cin >> x;
            while ( a[x] != 0 && x % a[x] == 0 ) ++q[a[x]], x /= a[x];
        }

        LL ans = 1;
        for (int i = 1; i < N; i++) {
            if ( q[i] < p[i] ) { cout << -1;return 0;}
            if ( q[i] == p[i] ) continue;
            ans = ( ans * ( Pow(q[i] - p[i] + 1,k,MOD) - ( 2*Pow(q[i]-p[i],k,MOD) ) % MOD + MOD + Pow(q[i]-p[i]-1,k,MOD) ) % MOD ) % MOD;
        }

    cout << ans;
    return 0;
}
