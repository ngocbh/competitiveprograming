#include <bits/stdc++.h>

const long N = 1000000 + 10;
const long MOD = 1000000000 + 7;

using namespace std;
typedef long long LL;
LL n, k, mp, md;
vector <int> a,b,c;

void calc_pr(LL x)
{
    mp = 0;
    LL  t = 2;
    while ( t * t <= x )
    {
        if ( x % t == 0 ) {
            LL tg = 0;
            while ( x % t == 0 ) x /= t, ++tg;
            a.push_back(t);
            b.push_back(tg);
            ++mp;
        }
        ++t;
    }
    if ( x > 1 ) {
        a.push_back(x);
        b.push_back(1);
        ++mp;
    }
}

void calc_dv()
{
    md = 1;
    c.push_back(1);
    for (int i = 0; i < mp; i++) {
        LL tg = 1;
        for (int j = 1; j <= b[i]; j++) {
            tg *= a[i];
            for (int it = 0; it < md; ++it){
                c.push_back(tg*c[it]);

            }
        }
        md *= b[i]+1;
    }
    sort(c.begin(),c.end());
}

LL tinhmu(LL a,LL k,LL p)
{
    LL r = 1, t = a, tg = k;
    while ( tg > 0 ) {
        if ( tg % 2 == 1 ) r = 1LL*t*r % p;
        t = 1LL*t*t % p;
        tg /= 2;
    }
    return r;
}

bool check(LL k,LL t)
{
    if ( tinhmu(10,t,k) != 1 ) return false;

    LL ty = 10,tx = 1, tg = t, ans = 0;
    while ( tg > 0 ) {
        if ( tg % 2 == 1 ) ans = (1LL*ans*ty + tx) % MOD;
        tx = (1LL*tx*ty+tx) % MOD;
        ty = (ty*ty) % MOD;
        tg /= 2;
    }

    ans = ( 1LL*ans* tinhmu(k,MOD-2,MOD) ) % MOD;
    cout << ans << endl;
    return true;
}

void solve(LL k)
{
    a.clear(); b.clear(); c.clear();
    calc_pr(k-1);
    calc_dv();

    if ( k < 10 ) {
        cout << 1 << endl;
        return;
    }

    for (int i = 0; i < md; i++) {
        if ( check(k,c[i]) ) return;
    }
}

int main()
{
        freopen("NUMPASS.inp","r",stdin);
        freopen("NUMPASS.out","w",stdout);
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> k;
            solve(k);
        }
}
