#include <bits/stdc++.h>

const long N = 1000000 + 10;
const long MOD = (int)(1e9+7);
using namespace std;
typedef long long LL;

LL n, m ,k;
LL a[N];

int main()
{   freopen("FERNS.inp","r",stdin);
    cin >> n >> k >> m;

    LL ans, cur , pm, pk, p0;
    ans = 1; pm = N-9-k+m; p0 = N-9-k; pk = N-9; a[p0+1] = 1;

    if (m > 1) cur = 0; else cur = 1;

    for (int i = 1; i <= n-1; i++) {
        cur = (cur + a[pm-1] - a[pk] + MOD) % MOD;
        ans = (ans + a[p0] - a[pk] + MOD) % MOD;
        --pm; --pk; --p0;
        a[p0] = cur;
    }

    cout << ans;

}
