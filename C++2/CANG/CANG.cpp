/*
    * CODE BY NGOCJR7
    * ALG of :
    * DPT O()
    * ALG :
*/

#include <bits/stdc++.h>

const long N = 100000 + 10;
const long oo = 1000000000 + 7;
const long MOD = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <LL,LL> ii;

int n, k;
LL a[N], b[N], c[N];
ii t[N];
int main()
{   freopen("CANG.inp","r",stdin);
    freopen("CANG.out","w",stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];

    int m = 0;
    for (int i = 1; i <= n; i++) {
        if ( k < a[i] ) continue;
        if ( (k - a[i]) % b[i] == 0 ) {
            t[++m].first = (k - a[i]) / b[i];
            t[m].second = i;
        }
    }

    sort(t+1,t+m+1);
    LL ans = 0, cur = 0, res = 0;
    t[0].first = -1;

    for (int i = 1; i <= m; i++) {
        res += c[t[i].second];
        if ( t[i].first != t[i-1].first ) {
            ans = max(ans,cur);
            cur = c[t[i].second];
        }
        else cur += c[t[i].second];
    }

    ans = max(ans,cur);

    cout << res;
}
