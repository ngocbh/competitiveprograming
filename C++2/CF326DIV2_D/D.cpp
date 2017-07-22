#include <bits/stdc++.h>

const long N = 1000000 + 10;
const long long MOD = 1000000000 + 7;
using namespace std;
typedef long long LL;

LL n, k , l;
LL a[N], t[N], t1[N], b[N], t2[N], f[N], x[N], cs[N];


void update(LL x,LL v)
{
    while ( x < N ) {
        t[x] = (t[x] + v) % MOD;
        x = x + (x & (-x) );
    }
}

LL findres(LL x)
{
    LL res = 0;
    while ( x > 0 ){
        res = (res + t[x]) % MOD;
        x = x - (x & (-x) );
    }
    return res;
}

bool cmp(int i,int j)
{
    return a[i] < a[j];
}

void rrh()
{
    int dem = 0;
    for (int i = 1; i <= n; i++) x[i] = a[i], cs[i] = i;

    sort(cs+1,cs+n+1,cmp);
    sort(x+1,x+n+1);

    x[0] = -1;
    for (int i = 1; i <= n; i++) {
        if ( x[i] == x[i-1] )
            a[cs[i]] = dem, b[cs[i]] = dem;
        else
            a[cs[i]] = ++dem, b[cs[i]] = dem;
    }
}

int main()
{   freopen("D.inp","r",stdin);
    //freopen("D.out","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> l >> k;

    for (int i = 1; i <= n; i++) cin >> a[i], b[i] = a[i];

    rrh();

    int kk = k;
    k = min(k,l/n);
    LL x = l % n;

    for (int i = 1; i <= n; i++) update(a[i],1);

    LL ans = findres(N-1);
    LL res = 0;
    LL rem = 0, prev = 0;
    for (int i = 1; i <= x; i++) t2[i] = 0;

    for (int i = 1; i < k; i++) {
        for (int j = 1; j <= n; j++) cout << (findres(a[j]) - findres(a[j]-1) + MOD*MOD ) % MOD << " "; cout << endl;
        for (int j = 1; j <= n; j++) {
                LL xx = findres(a[j]);
                t1[j] = xx + 1;
        }
        for (int j = 1; j <= n; j++) t[j] = 0;
        for (int j = 1; j <= n; j++) {
            update(a[j],t1[j]);
        }
        for (int j = 1; j <= n; j++) cout << (findres(a[j]) - findres(a[j]-1) + MOD*MOD ) % MOD << " "; cout << endl;
        prev = ans;
        ans = findres(N-1) % MOD;
        rem = ans - prev;
        if ( i == k-2+(k<kk) ) {
            for (int j = 1; j <= x; j++) {
                res += findres(a[j]) + 1;
                cout << a[j] << " " << findres(a[j]) << endl;
            }
        }
    }

    if ( k == 1 ) {
            for (int j = 1; j <= x; j++) {
                res += findres(a[j]);
            }
    }

    cout << rem << endl;
    ans = (ans + 1LL*rem*(((l/n) - k + 1) % MOD )) % MOD;
    ans = (ans + res) % MOD;
    cout << ans ;
}
