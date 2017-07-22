#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
typedef long long LL;
int n, p;
LL ans;
LL a[N], cs[N], f[N];

bool cmp(int i,int j)
{
        return a[i] < a[j];
}
int main()
{       freopen("JUMP.inp","r",stdin);
        freopen("JUMP.out","w",stdout);
        scanf("%d %d ", &n, &p);
        for (int i = 1; i <= n; i++) {
                scanf("%d", &a[i]);
                cs[i] = i;
        }
        sort(cs + 1, cs + n + 1, cmp);
        sort(a + 1, a + n + 1);
        f[n + 1] = 0;
        for (int i = n; i >= 1; i--) {
                f[i] = max(cs[i] , f[i+1]);
        }

        for (int i = 1; i <= n; i++) {
                int l = i, r = n, m, ii = 0;
                while ( r - l > 1 ) {
                        m = ( r + l ) / 2;
                        if ( a[m] >= a[i] + p ) r = m;
                        else l = m;
                }
                ii = l;
                if ( a[n] - a[i] < p ) continue;
                ans = max (ans , f[ii+1] - cs[i] );
        }
        printf("%lld", ans );
}
