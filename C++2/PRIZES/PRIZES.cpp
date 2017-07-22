#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
typedef long long LL;
struct ii{
    LL val, ind;
};

int n, k;
int a[N], s[N];
LL sum[N];
ii suma[N];
LL sums[N];
bool check(int x)
{
    if ( x < k ) return false;

    int cs = 0;
    for (int i = 1; i <= n; i++) {
        if ( i >= x - k + 1 && i <= x ) continue;
        s[++cs] = a[i];
    }

    for (int i = 1; i <= cs; i++) {
        if ( i <= k )
                sums[i] = sums[i-1] + s[i];
        else
                sums[i] = sums[i-1] + s[i] - s[i-k];
        if ( sums[i] > sum[x] ) return false;
    }

    return true;
}

bool cmp(ii A,ii B)
{
    return A.val < B.val;
}

int main()
{   freopen("PRIZES.inp","r",stdin);
    freopen("PRIZES.out","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if ( i <= k )
                suma[i].val = suma[i-1].val + a[i];
        else
                suma[i].val = suma[i-1].val + a[i] - a[i-k];
        suma[i].ind = i;
        sum[i] = suma[i].val;
    }

    sort(suma+1,suma+n+1,cmp);
    int l = 1, r = n, m , ans = 0;

    while ( l <= r ) {
            m = ( l + r ) / 2;
            if ( !check(suma[m].ind) )
                    l = m + 1, ans = suma[m+1].ind;
            else
                    r = m - 1;
    }

    int cs = 0;
    LL res = -1;
    for (int i = 1; i <= n; i++) {
        if ( i >= ans - k + 1 && i <= ans ) continue;
        s[++cs] = a[i];
    }

    for (int i = 1; i <= cs; i++) {
        if ( i <= k )
                sums[i] = sums[i-1] + s[i];
        else
                sums[i] = sums[i-1] + s[i] - s[i-k];
        res = max(sums[i],res);
    }

    cout << res ;
}
