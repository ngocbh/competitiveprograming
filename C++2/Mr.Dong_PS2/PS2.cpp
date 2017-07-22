#include <bits/stdc++.h>
#define x first
#define y second

const long N = 1000 + 10;
using namespace std;
typedef long long LL;
typedef pair <LL,LL> ii;

LL n, MOD, p, q;
LL d[N];

LL mutil(LL a,LL b,LL MOD)
{
    LL t = a, tg = b, r = 0;
    while ( tg > 0 ) {
        if ( tg % 2 == 1 ) r = ( r + t ) % MOD;
        t = (t+t)% MOD;
        tg /= 2;
    }
    return r;
}

int main()
{
    freopen("PS2.inp","r",stdin);
    freopen("PS2.out","w",stdout);

    cin >> n >> MOD;
    for (int i = 1; i <= n; i++) cin >> d[i];

    ii cur, a, b, c;
    a = ii(0,1); b = ii(1,0);
    cur = ii(1,1);

    for (int i = 1; i <= n; i++) {
        if ( d[i] == 0 ) continue;
        if ( i % 2 == 1 ) {
            c = cur;
            cur.x = (mutil(b.x,d[i],MOD) + c.x) % MOD;
            cur.y = (mutil(b.y,d[i],MOD) + c.y) % MOD;
            a.x = (mutil(b.x,d[i]-1,MOD) + c.x) % MOD;
            a.y = (mutil(b.y,d[i]-1,MOD) + c.y) % MOD;
            //cur.x = b.x*d[i] + a.x;
            //cur.y = b.y*d[i] + a.y;
        }
        else {
            c = cur;
            cur.x = (mutil(a.x,d[i],MOD) + c.x) % MOD;
            cur.y = (mutil(a.y,d[i],MOD) + c.y) % MOD;
            b.x = (mutil(a.x,d[i]-1,MOD) + c.x) % MOD;
            b.y = (mutil(a.y,d[i]-1,MOD) + c.y) % MOD;
            //cur.x = a.x*d[i] + b.x;
            //cur.y = a.y*d[i] + b.y;
        }
    }

    cout << cur.x << " " << cur.y;
}
